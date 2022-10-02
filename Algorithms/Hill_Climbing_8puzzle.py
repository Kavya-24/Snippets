import random
import time
import random
import itertools
import numpy as np
import time
from queue import PriorityQueue
from tabulate import tabulate

# to reshape string into matrix
def printStringMatrix(state_type, state_characters):
    print(state_type)
    temp=state_characters[:]
    print(np.reshape([*temp],(3,3)))

# to take start state, target state as input [from user] and store the indexes of respective elements in target state using dictionary
def readInputs():
  gridCharacters = input('Enter the start_state: ')
  targetCharacters = input('Enter the target_state: ')
  printStringMatrix('Source State', gridCharacters)
  printStringMatrix('Target State', targetCharacters)

  h2Dictionary = {}
  for e in range(len(targetCharacters)):
    x = int(e/3)
    y = int(e%3)
    h2Dictionary[targetCharacters[e]] = (x,y)
  return gridCharacters, targetCharacters, h2Dictionary

# function to find out the x and y coordinates of the blank element
def initialBlankCoordinates(gridCharacters):

    for i in range(len(gridCharacters)):
        if gridCharacters[i] == 'B':
            return i

    return -1

# traversing to valid states
def traverse(currentBlank, currentState):
  commandResults = [goRight,goLeft,goUp,goDown]  
  validNextStates = []
  for e in range(len(commandResults)):
    idx = commandResults[e](currentBlank)
    if idx != -1:
      cpy = currentState[:]
      newBlank = idx
      newBlankCharacter = cpy[newBlank]
      cpy = cpy[:currentBlank] + cpy[newBlank] + cpy[currentBlank+1:]
      cpy = cpy[:newBlank] + "B" + cpy[newBlank+1:]
      validNextStates.append((cpy,newBlank))
  return validNextStates

# accessing elements at (x-1,y), (x+1,y), (x,y-1) and (x,y+1) unless invalid
def goUp(idx):
    if idx > 2:
        return idx - 3
    return -1

def goDown(idx):
    if idx < 6:
        return idx + 3
    return -1

def goLeft(idx):
    if idx != 0 and idx != 3 and idx != 6:
        return idx -1
    return -1

def goRight(idx):
    if idx !=2 and idx != 5 and idx != 8:
        return idx + 1
    return -1

# class for State [current state, g(n), h(n), coordiantes of blank element]
class Priority_State:
    def __init__(self, _state, g_n, h_n, _blank):
        self.state = _state 
        self.g_n = g_n
        self.h_n = h_n
        self.blank_state = _blank

# for final output table
class HeuristicInformation_State:
      def __init__(self, algorithm, optimalPathCost, optimalPath,_path, parentList, timeTaken, reachable):
        self.algorithm = algorithm 
        self.optimalPathCost = optimalPathCost
        self.optimalPath = optimalPath
        self._path = _path
        self.parentList = parentList
        self.timeTaken = timeTaken
        self.reachable = reachable

# to call correct heuristic functions
def heuristic(op, intermediateCharacters, targetCharacters, h2Dictionary):
  if op == 1:
    return h1Heuristic(intermediateCharacters, targetCharacters)
  if op == 2:
    return h2Heuristic(intermediateCharacters, targetCharacters, h2Dictionary)

# Heuristic 1-> h(n)= Tiles displaced ignoring Blank character tile
def h1Heuristic(intermediateCharacters, targetCharacters):
  cnt = 0
  for e in range(len(targetCharacters)):
    if intermediateCharacters[e] != 'B' and intermediateCharacters[e] != targetCharacters[e]:
      cnt = cnt + 1
  return cnt

# Heuristic 2-> h(n)= Manhatten distance ignoring blank character tile
def h2Heuristic(intermediateCharacters, targetCharacters, h2Dictionary):
  dis = 0
  for e in range(len(intermediateCharacters)):
    if intermediateCharacters[e] != 'B':
      x = int(e / 3)
      y = e % 3
      # Index of intermediateCharacters[e] in target
      _x = h2Dictionary[intermediateCharacters[e]][0]
      _y = h2Dictionary[intermediateCharacters[e]][1]
      dis = dis + abs(x -_x) + abs(y -_y)
  return dis

# finding final path taken
def constructOptimalPath(parent_list, gridCharacters, targetCharacters):
    currentCharacters = targetCharacters
    optimalPath = []
    while currentCharacters != gridCharacters:
        optimalPath.append(currentCharacters)
        currentCharacters = parent_list[currentCharacters]   
    optimalPath.append(gridCharacters)   
    return optimalPath,printOptimalPath(optimalPath)

# printing path
def printOptimalPath(optimalPath):
    _path = ''
    for e in range(len(optimalPath) - 1, -1, -1):
        _path = _path + optimalPath[e] + '->'
    return _path[:-2]

# function to construct final output table 
def constructTable(hillclimbing_algorithms):
  headerData = ['Algorithm', 'Path Cost', 'Path States', 'Execution Time', 'Reachable',  'Path Traversed']
  tableData = []
  for h in hillclimbing_algorithms:
    rowValues = []
    rowValues.append(h.algorithm) 
    rowValues.append(h.optimalPathCost) 
    rowValues.append(len(h.optimalPath)) 
    rowValues.append(h.timeTaken)
    rowValues.append(h.reachable)
    rowValues.append(h._path)
    tableData.append(rowValues)
  print(tabulate(tableData, headers=headerData, tablefmt="grid"))

# for reachable/ unreachable states
def analyseAlgorithms(hillclimbing_algorithms):
  constructTable(hillclimbing_algorithms)
  return

# Hill CLimbing function
def HillClimbing(op,gridCharacters, targetCharacters,idx, h2Dictionary = {}):   
    
    # to continue searching for shoulder
    max_iterations = 50
    # parent's heuristic
    parent_heuristic = -1
    # for execution time
    start_time = time.time()
    # for final path
    parent_list = {}
    parent_list[gridCharacters]=gridCharacters
    # to keep track of visited states
    visitedDict = {}
    # number of discovered states
    cld = 0
  
    # mark current state visited
    visitedDict[gridCharacters] = 1
    # current state
    currentState = Priority_State(gridCharacters, 0, heuristic(op, gridCharacters, targetCharacters, h2Dictionary), idx)

    # traversing to neighbours
    while True:

      # if target reached
      if currentState.state == targetCharacters:
        return parent_list, True, currentState.g_n, currentState

      cld = cld + 1
      if currentState.h_n == parent_heuristic:
        max_iterations = max_iterations - 1
        if max_iterations < 0:
          print("Stuck in possible flat or shoulder for h("+str(op)+")")
          break
      else:
        max_iterations = 50
        parent_heuristic = currentState.h_n

      # find index of current blank tile
      currentBlank = currentState.blank_state
      validNextStates = traverse(currentBlank, currentState.state)
      
      # to check if we are getting stuck at local maxima
      local_maxima = True
      # valid neighbours
      options = 100
      best_neighbour = currentState

      # traversing valid neighbours and pushing in options, unless already visited
      for cpy,newBlank in validNextStates:

        if visitedDict.get(cpy) != None:
          continue
        visitedDict[cpy] = 1
        parent_list[cpy]=currentState.state
        heuristicValue = heuristic(op,cpy,targetCharacters,h2Dictionary)
        currentNeighbor = Priority_State(cpy,currentState.g_n+1, heuristicValue, newBlank)
        
        # if neighbour gives worse than current node
        if currentState.h_n < currentNeighbor.h_n:
          continue
        else:
          local_maxima = False
          # finding best valid neighbour
          if currentNeighbor.h_n < options:
            options = currentNeighbor.h_n
            best_neighbour = currentNeighbor

      if local_maxima:
          print("Stuck in local maxima for h("+str(op)+")")
          break
      else:
          currentState = best_neighbour
  
    return parent_list, False, 0, currentState

# utility function for calling Hill Climbing
def runHillClimbing(op, gridCharacters, targetCharacters,idx, algorithm, h2Dictionary = {}):
  start_time = time.time()
  parent_list, result, optimalPathCost, reachedTarget = HillClimbing(op, gridCharacters, targetCharacters, idx, h2Dictionary)
  
  optimalPath, _path = constructOptimalPath(parent_list, gridCharacters, reachedTarget.state)

  end_time = time.time()
  time_taken = end_time - start_time
  return HeuristicInformation_State(algorithm, optimalPathCost, optimalPath, _path, parent_list, time_taken, result)

# calling function for the initial matrix, target matrix and matrix- characters
gridCharacters, targetCharacters, h2Dictionary= readInputs()
# index of current blank element
idx  = initialBlankCoordinates(gridCharacters)

hillclimbing_algorithms = []
hillclimbing_algorithms.append(runHillClimbing(1,gridCharacters,targetCharacters,idx,'h1(n)',h2Dictionary))
hillclimbing_algorithms.append(runHillClimbing(2,gridCharacters,targetCharacters,idx,'h2(n)',h2Dictionary))

analyseAlgorithms(hillclimbing_algorithms)

# Enter the start_state: B23145678, 
# Enter the target_state: 2431B5678  (TRUE) and 12345867B (FALSE)
# 7B2453681
