
#Importing python packages
import numpy as np
import copy
import time
from heuristics import h1,h2,h3,h4
from queue import PriorityQueue

# To print the current state and return the position of the blank
def print_state(state):
  a=0
  b=0
  for i in range(3):
    for j in range(3):
      if(state[i][j]==0):
        a = i
        b = j
        print('B',end=' ')
      else:
        print(str(state[i][j]),end=' ')
    print('')
  print('')
  return [a,b]

# Function to return hash of the state after converting it into bytes
def state_to_hash(state):
  return hash(state.tobytes())

# Function to convert state into hashable tuple
def to_tuple(state):
  state = state.tolist()
  return tuple([tuple(state[0]),tuple(state[1]),tuple(state[2])])

# The Function to calculate Heuristics based on h_value
def h(state, final_state, empty_tile, h_value):
  if(h_value == 1):
    return h1(state, final_state, empty_tile)
  elif (h_value == 2):
    return h2(state, final_state, empty_tile)
  elif (h_value == 3):
    return h3(state, final_state, empty_tile)
  else:
    return h4(state, final_state, empty_tile)

# Queue Element Format
class queue_ele:
  def __init__(self, ele: list):
    self.ele = ele

  def __lt__(self, other):
    # Comparing f(n) cost
    if self.ele[0] == other.ele[0]:
      return self.ele[1] < other.ele[1]
    return self.ele[0] < other.ele[0]

  # Returning the list
  def ret_ele(self):
    return self.ele

# A* main function

# state = initial state,   
# final_state = hash of the final state,
# m,n = dimensions of the state
# h_value = heuritics function option
# empty_tile = to check if empty tile's heuristics can be taken 

def astar(initial_state, final_state, m, n, h_value, empty_tile):

  # Printing Initial State
  print('Initial State')
  init_pos = print_state(initial_state)

  # i,j = position of the blank space
  i = init_pos[0]
  j = init_pos[1]

  # Printing Final State
  print('\nFinal State')
  print_state(final_state)

  # Recording start time
  start_time = time.time()

  # Queue (open list)
  # 1st element: Least cost from source state to current state so far
  # 2nd element: Heuristics
  # 3rd element: Current State
  # 4th,5th elements: position of blank space 
  queue = PriorityQueue()
  h_n = h(initial_state, final_state, empty_tile, h_value)
  queue.put(queue_ele([0 + h_n, 0, h_n, initial_state, i, j]))

  # Storing path travesal, stores the parent state from which it is derived.
  parent = dict()

  # Storing g(state) of states
  g_state_list = dict()

  final_state_hash = state_to_hash(final_state)

  # Expanded states (closed list)
  expanded_states = dict()

  # Optimal Path Cost
  optimal_cost = 0

  while(queue.qsize()>0):
    # Finding and popping minimum f(state) cost element
    cost_state, g_state, h_state, state, i, j = queue.get().ret_ele()
    
    state_hash = state_to_hash(state)
    expanded_states[state_hash] = 0

    if state_hash in g_state_list:
      g_state_list[state_hash] = min(g_state_list[state_hash], g_state)
    else:
      g_state_list[state_hash] = g_state 

    p = i
    q = j

    state_tuple = to_tuple(state)

    # Final state reached
    if(state_hash == final_state_hash):
      optimal_cost = cost_state
      break
    
    # Shifting the blank space up
    if p>0:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p-1][q]
      tmp_state[p-1][q] = tmp_state[p][q]
      tmp_state[p][q] = tmp
      tmp_hash = state_to_hash(tmp_state)

      if(tmp_hash not in g_state_list):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p-1, q]))
      
      elif (g_state + 1 < g_state_list[tmp_hash]):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p-1, q]))
      
    # Shifting the blank space left
    if q>0:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p][q-1]
      tmp_state[p][q-1] = tmp_state[p][q]
      tmp_state[p][q] = tmp
      tmp_hash = state_to_hash(tmp_state)

      if(tmp_hash not in g_state_list):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p, q-1]))

      elif (g_state + 1 < g_state_list[tmp_hash]):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p, q-1]))

    # Shifting the blank space down
    if p<m-1:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p+1][q]
      tmp_state[p+1][q] = tmp_state[p][q]
      tmp_state[p][q] = tmp
      tmp_hash = state_to_hash(tmp_state)

      if(tmp_hash not in g_state_list):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p+1, q]))

      elif (g_state + 1 < g_state_list[tmp_hash]):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p+1, q]))

    # Shifting the blank space right
    if q<n-1:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p][q+1]
      tmp_state[p][q+1] = tmp_state[p][q]
      tmp_state[p][q] = tmp
      tmp_hash = state_to_hash(tmp_state)

      if(tmp_hash not in g_state_list):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p, q+1]))
      
      elif (g_state + 1 < g_state_list[tmp_hash]):
        parent[to_tuple(tmp_state)] = state_tuple
        g_state_list[tmp_hash] = g_state + 1
        h_n = h(tmp_state, final_state, empty_tile, h_value)
        
        # Checking for monotone restriction
        if h_state > h_n + 1:
          print('Monotone restriction voilated!')
          return []
        
        queue.put(queue_ele([h_n + g_state + 1, g_state + 1, h_n, tmp_state, p, q+1]))
  
  # Calculating Time taken by the Algorithm
  total_time_taken = time.time() - start_time

  # Checking if final state reached
  if expanded_states.get(final_state_hash, -1) == -1:
    # The Final state is unreachable from this Initial state
    print('The Final state is not reachable from the given Initial State')
    print('Total number of states expanded before termination: ', len(expanded_states), ' states')
    return list(expanded_states.keys())

  # Final state reached
  print('\nThe Final state is reachable from the given Initial State')
  print('Total number of states in optimal path(including Final state): ', g_state_list[final_state_hash]+1, ' states')
  print('Total number of states expanded: ', len(expanded_states), ' states')
  print('Optimal Path Cost: ', optimal_cost)
  print('Total Time taken in milliseconds by the algorithm: ' + str(total_time_taken*1000))
  
  curr_state = to_tuple(final_state)
  initial_hash = hash(to_tuple(initial_state))
  path = []
  while(1):
    path.append(curr_state)
    if hash(curr_state) == initial_hash:
      break
    curr_state = parent[curr_state]
  
  path.reverse()

  print('\nOptimal Path: ')
  print('Initial State')
  print_state(path[0])

  print('\n1st Step')
  print_state(path[1])

  print('\n2nd Step')
  print_state(path[2])

  print('\n...Final State')
  print_state(path[-1])

  return list(expanded_states.keys())


def use_astar(initial_state, final_state, empty_tile):
  
  print('\n~~A* Algo~~') 

  print('~~~~Using h1(n)~~~~\n')
  expanded_states_h1 = astar(initial_state, final_state, 3, 3, 1, empty_tile)

  print('\n\n~~~~Using h2(n)~~~~\n')
  expanded_states_h2 = astar(initial_state, final_state, 3, 3, 2, empty_tile)

  print('\n\n~~~~Using h3(n)~~~~\n')
  expanded_states_h3 = astar(initial_state, final_state, 3, 3, 3, empty_tile)

  print('\n\n~~~~Using h4(n)~~~~\n')
  expanded_states_h4 = astar(initial_state, final_state, 3, 3, 4, empty_tile)

  # Q2
  print("\nAll the states expanded by h3(superior) should also be in h2(inferior): ", set(expanded_states_h3).issubset(expanded_states_h2))
  print("All the states expanded by h2(superior) should also be in h1(inferior): ", set(expanded_states_h2).issubset(expanded_states_h1))