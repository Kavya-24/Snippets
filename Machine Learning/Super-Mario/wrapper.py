import torch
import numpy as np
from torchvision import transforms as T
import gym
from gym.spaces import Box
from gym.wrappers import FrameStack
from nes_py.wrappers import JoypadSpace
import gym_super_mario_bros


#SkipFrame is a custom wrapper that inherits from gym.Wrapper and implements
#the step() function. Because consecutive frames don’t vary much, we can skip
#n-intermediate frames without losing much information. The n-th frame aggregates
#rewards accumulated over each skipped frame.


class SkipFrame(gym.Wrapper):
    def __init__(self,env,skip):
        super().__init__(env)
        self._skip = skip # number of frames to be skipped

    def step(self,action):
        total_reward = 0.0
        done = False
        for i in range(self._skip):
            obs ,reward, done , info = self.env.step(action)
            total_reward += reward
            if done:
                break

        return obs, total_reward,done,info


#useful wrapperclass to conver rgb to grayscale image
class GrayScaleObservation(gym.ObservationWrapper):
    def __init__(self,env):
        super().__init__(env)
        obs_shape = self.observation_space.shape[:2]

    def permute_orientation(self,observation):
        observation = np.transpose(observation,(2,0,1))
        observation = torch.tensor(observation.copy(),dtype=torch.float)
        return observation

    def observation(self,observation):
        observation = self.permute_orientation(observation)
        transform = T.Grayscale()
        observation = transform(observation)
        return observation


#ResizeObservation downsamples each observation into a square image. New size: [1, 84, 84]

class ResizeObservation(gym.ObservationWrapper):

    def __init__(self,env,shape):
        super().__init__(env)
        if isinstance(shape,int): # if single value provided as shape --> obviously square frame
            self.shape = (shape,shape)
        else:
            self.shape = tuple(shape)

        obs_shape = self.shape + self.observation_space.shape[2:]#last channel of observation frame img
        self.observaion_space = Box(low=0,high=255,shape=obs_shape,dtype = np.uint8)
        #...............................................^

    def observation(self,observation):
        transforms = T.Compose([T.Resize(self.shape),T.Normalize(0,255)])
        observation = transforms(observation).squeeze(0) # (1,x,x) -> (x,x)
        return observation

'''
FrameStack is a wrapper that allows us to squash consecutive frames of the
environment into a single observation point to feed to our learning model.
This way, we can identify if Mario was landing or jumping based on the
direction of his movement in the previous several frames.
'''
