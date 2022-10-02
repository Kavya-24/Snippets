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

  h3Dictionary = {}
  for e in range(len(targetCharacters)):
    x = int(e/3)
    y = int(e%3)
    h3Dictionary[targetCharacters[e]] = (x,y)
  return gridCharacters, targetCharacters, h3Dictionary


# function to find out the x and y coordinates of the blank element
def initialBlankCoordinates(gridCharacters):

    for i in range(len(gridCharacters)):
        if gridCharacters[i] == 'B':
            return i

    return -1

# class for priority queue [current state, g(n), h(n), coordiantes of blank element]
class Priority_State:
    def __init__(self, _state, g_n, h_n, _blank):
        self.state = _state 
        self.g_n = g_n
        self.h_n = h_n
        self.blank_state = _blank

    # since we need priority queue in descending order
    def __lt__(self, other):
        if (self.g_n + self.h_n) == (other.g_n + other.h_n):
            return self.g_n < other.g_n
        return (self.g_n + self.h_n) < (other.g_n + other.h_n)

# for final output table
class HeuristicInformation_State:
      def __init__(self, algorithm, optimalPathCost, optimalPath,_path,  exploredStates, parentList, timeTaken, reachable, flag):
        self.algorithm = algorithm 
        self.optimalPathCost = optimalPathCost
        self.optimalPath = optimalPath
        self._path = _path
        self.exploredStates = exploredStates
        self.parentList = parentList
        self.timeTaken = timeTaken
        self.reachable = reachable
        self.flag = flag

# to call correct heuristic functions
def heuristic(op, intermediateCharacters, targetCharacters, h3Dictionary):
  if op == 1:
    return h1Heuristic(intermediateCharacters, targetCharacters)
  if op == 2:
    return h2Heuristic(intermediateCharacters, targetCharacters)
  if op == 3:
    return h3Heuristic(intermediateCharacters, targetCharacters, h3Dictionary)
  if op == 4:
    return h4Heuristic(intermediateCharacters, targetCharacters, h3Dictionary)
  if op == 5:
    return h5Heuristic(intermediateCharacters, targetCharacters)
  if op == 6:
    return h6Heuristic(intermediateCharacters, targetCharacters, h3Dictionary)

# Heuristic 1-> h(n)=0
def h1Heuristic(intermediateCharacters, targetCharacters):
  return 0

# Heuristic 2-> h(n)= Tiles displaced ignoring Blank character tile
def h2Heuristic(intermediateCharacters, targetCharacters):
  cnt = 0
  for e in range(len(targetCharacters)):
    if intermediateCharacters[e] != 'B' and intermediateCharacters[e] != targetCharacters[e]:
      cnt = cnt + 1
  return cnt

# Heuristic 3-> h(n)= Manhatten distance ignoring blank character tile
def h3Heuristic(intermediateCharacters, targetCharacters, h3Dictionary):
  dis = 0
  for e in range(len(intermediateCharacters)):
    if intermediateCharacters[e] != 'B':
      x = int(e / 3)
      y = e % 3
      # Index of intermediateCharacters[e] in target
      _x = h3Dictionary[intermediateCharacters[e]][0]
      _y = h3Dictionary[intermediateCharacters[e]][1]
      dis = dis + abs(x -_x) + abs(y -_y)
  return dis

# Heuristic 4-> h(n)= Number of tiles out of column + Number of tiles out of row
def h4Heuristic(intermediateCharacters, targetCharacters, h3Dictionary):
  cntrow = 0
  cntcol = 0
  for e in range(len(intermediateCharacters)):
    if intermediateCharacters[e] != 'B':
      x = int(e / 3)
      y = e % 3
      # Index of intermediateCharacters[e] in target
      _x = h3Dictionary[intermediateCharacters[e]][0]
      _y = h3Dictionary[intermediateCharacters[e]][1]
      if x != _x:
        cntrow = cntrow + 1
      if y != _y:
        cntcol = cntcol + 1
  return cntrow + cntcol

# Heuristic 5-> h(n)= Tiles displaced including Blank character tile
def h5Heuristic(intermediateCharacters, targetCharacters):
  cnt = 0
  for e in range(len(targetCharacters)):
    if intermediateCharacters[e] != targetCharacters[e]:
      cnt = cnt + 1
  return cnt

# Heuristic 6-> h(n)= Manhatten distance including Blank character 
def h6Heuristic(intermediateCharacters, targetCharacters, h3Dictionary):
  dis = 0
  for e in range(len(intermediateCharacters)):      
      x = int(e / 3)
      y = e % 3
      # Index of intermediateCharacters[e] in target
      _x = h3Dictionary[intermediateCharacters[e]][0]
      _y = h3Dictionary[intermediateCharacters[e]][1]     
      dis = dis + abs(x -_x) + abs(y -_y)
  return dis

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

# finding final optimal path taken
def constructOptimalPath(parent_list, gridCharacters, targetCharacters):
    currentCharacters = targetCharacters
    optimalPath = []
    while currentCharacters != gridCharacters:
        optimalPath.append(currentCharacters)
        currentCharacters = parent_list[currentCharacters]   
    optimalPath.append(gridCharacters)   
    return optimalPath,printOptimalPath(optimalPath)

# printing optimal path
def printOptimalPath(optimalPath):
    _path = ''
    for e in range(len(optimalPath) - 1, -1, -1):
        _path = _path + optimalPath[e] + '->'
    return _path[:-2]

# Astar function
def AStar(op,gridCharacters, targetCharacters,idx, h3Dictionary = {}):   
    # to check monotonicity restriction
    flag = 0
    # for execution time
    start_time = time.time()
    # for optimal path
    parent_list = {}
    # to keep track of visited states
    visitedDict = {}   
    # to keep track of discovered but not explored states           
    open_list = PriorityQueue()
    # to keep track of explored states
    close_list = []
    source_h = heuristic(op, gridCharacters, targetCharacters, h3Dictionary)

    # to keep track of visited configurations
    visitedDict[gridCharacters] = 1
    open_list.put(Priority_State(gridCharacters, 0, source_h, idx))
    # number of discovered states
    cld = 0

    while not open_list.empty():
      m = open_list.get()
      close_list.append(m.state)
      if m.state == targetCharacters:
        return close_list, parent_list, True, m.g_n, flag

      currentBlank = m.blank_state
      validNextStates = traverse(currentBlank, m.state)

      for cpy,newBlank in validNextStates:
        # checking if configuration is already present in visited   
        if visitedDict.get(cpy) == None:
          visitedDict[cpy] = 1
          cld = cld + 1
          parent_list[cpy]=m.state
          heuristicValue = heuristic(op,cpy,targetCharacters, h3Dictionary)
          open_list.put(Priority_State(cpy,m.g_n+1, heuristicValue, newBlank))
          # monotonicity condition
          if m.h_n > 1 + heuristicValue:
            flag = 1
      
    return close_list, parent_list, False, 0, flag

# utility function for calling AStar
def runAStar(op, gridCharacters, targetCharacters,idx, algorithm, h3Dictionary = {}):
  start_time = time.time()
  close_list, parent_list, result, optimalPathCost, flag = AStar(op, gridCharacters, targetCharacters, idx, h3Dictionary)
  optimalPath = []
  _path = ''
  if result == True:
    optimalPath, _path = constructOptimalPath(parent_list, gridCharacters, targetCharacters)

  end_time = time.time()
  time_taken = end_time - start_time
  return HeuristicInformation_State(algorithm, optimalPathCost, optimalPath, _path, close_list, parent_list, time_taken, result,flag)

# function to check if all states explored by better heuristics are also explored by worse heuristics
def compareHeuristics(algorithm_better,  close_list_better, algorithm,close_list):
  cnt = 0
  for s in close_list_better:
    if s in close_list:
      cnt = cnt + 1
  if cnt == len(close_list_better):
    print('All the states explored by ' + str(algorithm_better) + ' are explored by ' + str(algorithm))
  else:
    print('All the states explored by ' + str(algorithm_better) + ' are NOT explored by ' + str(algorithm))
  return

def compareStates(astar_algorithms):  
  for k1 in astar_algorithms:
    for k2 in astar_algorithms:
      if k1 != k2 and k1.algorithm != "h5(n)" and k1.algorithm != "h6(n)" and k2.algorithm != "h5(n)" and k2.algorithm != "h6(n)":
        compareHeuristics(k1.algorithm, k1.exploredStates,k2.algorithm, k2.exploredStates)

# function to construct final output table 
def constructTable(astar_algorithms):
  headerData = ['Algorithm', 'Optimal Cost', '#Optimal Cost States', '#Explored States', 'Execution Time', 'Reachable', 'Monotonic', 'Optimal Path']
  tableData = []
  for h in astar_algorithms:
    rowValues = []
    rowValues.append(h.algorithm) 
    rowValues.append(h.optimalPathCost) 
    rowValues.append(len(h.optimalPath)) 
    rowValues.append(len(h.exploredStates))
    rowValues.append(h.timeTaken)
    rowValues.append(h.reachable)
    if h.flag==1:
      rowValues.append(False)
    else:
      rowValues.append(True)
    rowValues.append(h._path)
    tableData.append(rowValues)
  print(tabulate(tableData, headers=headerData, tablefmt="grid"))

# for reachable/ unreachable states
def analyseAlgorithms(astar_algorithms):
  constructTable(astar_algorithms)
  if astar_algorithms[0].reachable == False:
    return
  compareStates(astar_algorithms)
  return

# calling function for the initial matrix, target matrix and matrix- characters
gridCharacters, targetCharacters, h3Dictionary= readInputs()
# index of current blank element
idx  = initialBlankCoordinates(gridCharacters)

astar_algorithms = []
astar_algorithms.append(runAStar(1,gridCharacters,targetCharacters,idx,'h1(n)',h3Dictionary))
astar_algorithms.append(runAStar(2,gridCharacters,targetCharacters,idx,'h2(n)',h3Dictionary))
astar_algorithms.append(runAStar(3,gridCharacters,targetCharacters,idx,'h3(n)',h3Dictionary))
astar_algorithms.append(runAStar(4,gridCharacters,targetCharacters,idx,'h4(n)',h3Dictionary))
astar_algorithms.append(runAStar(5,gridCharacters,targetCharacters,idx,'h5(n)',h3Dictionary))
astar_algorithms.append(runAStar(6,gridCharacters,targetCharacters,idx,'h6(n)',h3Dictionary))
analyseAlgorithms(astar_algorithms)
