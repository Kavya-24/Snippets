
#Importing python packages
import numpy as np
import copy
import time

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


# DFS main function

# state = initial state, 
# i,j = position of the blank space,  
# final_state = hash of the final state, 
# visited_states = dictionary to store hash of visited states
# m,n = dimensions of the state
# parent = stores the parent state from which it is derived.

def dfs(state, i, j, final_state, visited_states, m, n, parent):

  # Stack to implement DFS behaviour, here stack top is the end of the list.
  stack = []
  stack.append([state, i, j])

  while(len(stack)>0):
    state, i, j = stack[-1]
    stack.pop()
    p = i
    q = j

    # Marking state as visited
    visited_states[state_to_hash(state)] = 0

    state_tuple = to_tuple(state)

    # Final state reached
    if(state_to_hash(state) == final_state):
      return
    
    # Shifting the blank space up
    if p>0:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p-1][q]
      tmp_state[p-1][q] = tmp_state[p][q]
      tmp_state[p][q] = tmp
      
      if(visited_states.get(state_to_hash(tmp_state), 1)):
        parent[to_tuple(tmp_state)] = state_tuple
        stack.append([tmp_state, p-1, q])
    
    # Shifting the blank space left
    if q>0:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p][q-1]
      tmp_state[p][q-1] = tmp_state[p][q]
      tmp_state[p][q] = tmp

      if(visited_states.get(state_to_hash(tmp_state), 1)):
        parent[to_tuple(tmp_state)] = state_tuple
        stack.append([tmp_state, p, q-1])

    # Shifting the blank space down
    if p<m-1:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p+1][q]
      tmp_state[p+1][q] = tmp_state[p][q]
      tmp_state[p][q] = tmp

      if(visited_states.get(state_to_hash(tmp_state), 1)):
        parent[to_tuple(tmp_state)] = state_tuple
        stack.append([tmp_state, p+1, q])

    # Shifting the blank space right
    if q<n-1:
      tmp_state = copy.deepcopy(state)
      tmp = tmp_state[p][q+1]
      tmp_state[p][q+1] = tmp_state[p][q]
      tmp_state[p][q] = tmp

      if(visited_states.get(state_to_hash(tmp_state), 1)):
        parent[to_tuple(tmp_state)] = state_tuple
        stack.append([tmp_state, p, q+1])

# if __name__ == "__main__":
def use_dfs(initial_state, final_state):

  step_dfs = -1

  # Zero is taken as the blank one
  # initial_state = np.arange(9)
  # np.random.shuffle(initial_state)
  # initial_state = initial_state.reshape(3, -1)

  # Storing visited states as Hash in Python Dictionary
  visited_states = dict()
  visited_states[state_to_hash(initial_state)] = 0

  # Storing path travesal
  parent = dict()
  
  # Final State
  # final_state = np.array([1,2,3,4,5,6,7,8,0]).reshape(3,-1)
  
  print('\n~~DFS Algo~~\n')

  # Printing Initial State and Final State
  print('Initial State')
  init_pos = print_state(initial_state)

  print('Final State')
  print_state(final_state)

  # Recording start time
  start_time = time.time() 

  # Calling the DFS function
  dfs(initial_state, init_pos[0], init_pos[1], state_to_hash(final_state), visited_states, 3,3, parent)
  
  # Calculating Time taken by the DFS Algorithm
  total_time_taken = time.time() - start_time

  # Checking if final state reached
  if parent.get(to_tuple(final_state), -1) != -1:
    state = to_tuple(final_state)
    step_dfs = 0
    initial_hash = hash(to_tuple(initial_state))
    path = []
    while(1):
      path.append(state)
      if hash(state) == initial_hash:
        break
      state = parent[state]
      step_dfs = step_dfs + 1
    
    path.reverse()

    # Printing the number of steps
    print('Number of steps taken to reach the Final State by DFS: ' + str(step_dfs))

    # Number of states processed
    print('Number of states reached by DFS: ' + str(len(parent)))

    # Printing the time taken
    print('Total Time taken in milliseconds by DFS: ' + str(total_time_taken*1000) + '\n')

    # Printing the path
    # print('Path: \n')
    # for i in range(len(path)):
    #   print_state(path[i])
  else:
    # The Final state is unreachable from this Initial state
    print('The Final state is not reachable from the given Initial State')