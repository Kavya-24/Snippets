#pytorch import
import torch
import numpy as np


#python essential imports
from pathlib import Path
from collections import deque
import random, datetime, os, copy
import time, datetime


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


#make super mario env
env = gym_super_mario_bros.make("SuperMarioBros-1-2-v0")
env = JoypadSpace(env,[["right"],["right","A"]])
env.reset()


next_state,reward,done,info = env.step(action=0)
print(f"{next_state.shape}, \n {reward},\n {done},\n {info}")



from wrapper import SkipFrame, GrayScaleObservation, ResizeObservation


# apply wrappers to the env
env = SkipFrame(env,skip = 4)
env = GrayScaleObservation(env)
env = ResizeObservation(env,shape=84)
env = FrameStack(env,num_stack=4)

'''
After applying the above wrappers to the environment, the final wrapped state
consists of 4 gray-scaled consecutive frames stacked together, as shown above
in the image on the left. Each time Mario makes an action, the environment
responds with a state of this structure. The structure is represented by a
3-D array of size [4, 84, 84]
'''


use_cuda = torch.cuda.is_available()
print(f"Using CUDA : {use_cuda}")
print()


save_dir = Path("checkpoints") / datetime.datetime.now().strftime("%Y-%m-%dT%H-%M-%S")
save_dir.mkdir(parents=True)


#import Mario class
from mario import Mario
from metriclogger import MetricLogger

mario = Mario(state_dim = (4,84, 84), action_dim=env.action_space.n, save_dir=save_dir)
logger = MetricLogger(save_dir)


episodes = 2000
for e in range(episodes):
    state = env.reset()

    # Play the Game
    while 1:
        action = mario.act(state)
        next_state, reward, done, info = env.step(action)
        #img = plt.imshow(
        env.render()
        #vid.append([img])

        mario.cache(state, next_state, action, reward, done)

        #learn
        q, loss = mario.learn()

        #logging
        logger.log_step(reward, loss, q)

        #update state
        state = next_state

        #check if end of game
        if done or info["flag_get"]:
            break


    logger.log_episode()

    if e%20 == 0:
        logger.record(episode=e, epsilon=mario.exploration_rate, step=mario.curr_step)

