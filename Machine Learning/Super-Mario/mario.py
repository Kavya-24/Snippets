import torch
from torch import nn
from torchvision import transforms as T
from PIL import Image
import numpy as np
from pathlib import Path
from collections import deque
import random, datetime, os, copy

#matplotlib imports
import matplotlib.pyplot as plt
import matplotlib.animation as animation


#gym imports
import gym
from gym.spaces import Box
from gym.wrappers import FrameStack
from nes_py.wrappers import JoypadSpace
import gym_super_mario_bros


#device
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")


class Mario:

    def __init__(self,state_dim,action_dim,save_dir):
        self.state_dim = state_dim
        self.action_dim = action_dim
        self.save_dir = save_dir
        self.use_cuda = torch.cuda.is_available()
        #Mario net -> for learning
        self.net = MarioNet(self.state_dim,self.action_dim).float()

        if self.use_cuda:
            self.net = self.net.to(device="cuda")

        self.exploration_rate = 1
        self.exploration_rate_decay = 0.99999975
        self.exploration_rate_min = 0.1
        self.curr_step = 0

        self.save_every = 10

        self.memory = deque(maxlen=100000)
        self.batch_size = 32

    def act(self,state):
        # Given a state , choose an epsilon greedy action and update value of step

        #inputs:
        #state(LazyFrame):A single observation of the current state, dimensio = (state_dim)

        #outputs:
        #action_idx(int):an integer representing which action mario will perform

        #EXPLORE
        if np.random.rand()<self.exploration_rate:
            action_idx = np.random.randint(self.action_dim) # parameter passed is lower bound

        #EXPLOIT
        else:
            state = state.__array__() #we can get a copy of an array that doesn’t change the
                                    #data element of original array if we change any element in the new one

            if self.use_cuda:
                state = torch.tensor(state).cuda()
            else:
                state = torch.tensor(state)

            state = state.unsqueeze(0)
            action_values = self.net(state,model="online")
            action_idx = torch.argmax(action_values,axis=1).item() # .item() method to
                        #get a python int from a torch tensor containing single value

        #decrease exploration rate
        self.exploration_rate += self.exploration_rate_decay
        self.exploration_rate = max(self.exploration_rate_min,self.exploration_rate)

        #increment step
        self.curr_step+=1

        return action_idx


    #following two functions are for Mario's memory

    def cache(self, state, next_state, action, reward, done):
        '''
        Each time Mario performs an action, he stores the experience to his memory. His
        experience includes the current state, action performed, reward from the action,
        the next state, and whether the game is done

        saves experience to self.memory

        Inputs:
        state (LazyFrame),
        next_state (LazyFrame),
        action (int),
        reward (float),
        done(boolean)
        '''
        print(type(state))
        state = state.__array__()
        next_state = next_state.__array__()


        state = torch.tensor([state]).to(device)
        next_state = torch.tensor([next_state]).to(device)
        action = torch.tensor([action]).to(device)
        done = torch.tensor([done]).to(device)

        self.memory.append((state,next_state,action,reward,done,))

    def recall(self):
        # retrieve a batch of experience from memory

        batch = random.sample(self.memory, self.batch_size)
        
        state, next_state, action, reward, done = map(torch.stack, zip(*batch))
        
        
        state = torch.tensor(state)
        next_state = torch.tensor(next_state)
        action = torch.tensor(action)
        reward = torch.tensor(reward)
        done = torch.tensor(done)
        
        return state, next_state, action.squeeze() ,reward.squeeze(), done.squeeze()


class MarioNet(nn.Module):
    '''
    input -> 3 x (conv2d + relu) -> flatten -> 2 x (dense + relu) -> output
    '''

    def __init__(self,input_dim,output_dim):
        super().__init__()
        c,h,w = input_dim

        if h != 84:
            raise ValueError(f"Expecting input height : 84, got : {h}")

        if w != 84:
            raise ValueError(f"Expecting input height : 84, got : {h}")

        self.online = nn.Sequential(
            nn.Conv2d(in_channels=c, out_channels=32, kernel_size = 8, stride=4),
            nn.ReLU(),
            nn.Conv2d(in_channels=32, out_channels=64 , kernel_size = 4, stride=2),
            nn.ReLU(),
            nn.Conv2d(in_channels=32, out_channels=64 , kernel_size = 4, stride=2),
            nn.ReLU(),
            nn.Flatten(),
            nn.Linear(3136,512),
            nn.ReLU(),
            nn.Linear(512, output_dim),
        )

        self.target = copy.deepcopy(self.online)

        for p in self.target.parameters():
            p.requires_grad = False


    def forward(self,input,model):
        if model == 'online':
            return self.online(input)
        elif model== 'target':
            return self.target(input)
        else:
            raise TypeError("Invalid model argument")


class Mario(Mario):

    def __init__(self, state_dim, action_dim, save_dir):
        super().__init__(state_dim,action_dim,save_dir)
        self.gamma = 0.9

    def td_estimate(self, state, action):
        current_Q = self.net(state,model="online")[
            np.arange(0,self.batch_size), action
        ]

        # Q_online(s,a)
        return current_Q

    @torch.no_grad()
    def td_target(self, reward, next_state, done):

        next_state_Q = self.net(next_state,model="online")
        best_action = self.argmax(next_state_Q, axis=1)

        next_Q = self.net(next_state,model = 'target')[
            np.arange(0, self.batch_size), best_action
        ]

        return (reward + (1 - done.float()) * self.gamma * next_Q).float()


class Mario(Mario):

    def __init__(self, state_dim, action_dim, save_dir):
        super().__init__(state_dim, action_dim, save_dir)
        self.optimizer = torch.optim.Adam(self.net.parameters(), lr=0.00025)
        self.loss_fn = torch.nn.SmoothL1Loss()

    def update_Q_online(self, td_estimate, td_target):
        loss = self.loss_fn(td_estimate, td_target)
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()

        return loss.item()

    def sync_Q_target(self):
        # copy online model into target model
        self.net.target.load_state_dict(self.net.online.state_dict())

    # save checkpoint
    def save(self):
        save_path = (
            self.save_dir / f"mario_net_{int(self.curr_step//self.save_every)}.chkpt"
        )
        torch.save(
            dict(model=self.net.state_dict(),exploration_rate=self.exploration_rate),
            save_path,
        )
        print(f"MarioNet saved to {save_path} at step {self.curr_step}")


class Mario(Mario):
    def __init__(self, state_dim, action_dim, save_dir):
        super().__init__(state_dim, action_dim, save_dir)
        self.burnin = 1e4       # min. experiences before training
        self.learn_every = 3    # no. of experiences between updates to Q_online
        self.sync_every = 100   # no. of experiences between Q_target & Q_online sync

    def learn(self):

        if self.curr_step % self.sync_every == 0:
            self.sync_Q_target()
        if self.curr_step % self.save_every == 0:
            self.save()
        if self.curr_step <self.burnin:
            return None, None
        if self.curr_step % self.learn_every != 0:
            return None, None

        # Sample from memory
        state, next_state, action, reward, done = self.recall()

        #get td estimate and target
        td_est = self.td_estimate(state, action)
        td_tgt = self.td_target(reward, next_state, done)

        loss = self.update_Q_online(td_est, td_tgt)

        return (td_est.mean().item(), loss)


