# Functions for heuristics

# Zero heuristic
def h1(state, final_state, empty_tile):
  return 0

# Number of tiles displaced from their destined position heuristic
def h2(state, final_state, empty_tile):
  h_state = 0
  for i in range(3):
    for j in range(3):
    # Checking if value for empty tile should be taken or not
      if(empty_tile):
        if state[i][j] != final_state[i][j]:
          h_state += 1
      else:
        if state[i][j]!=0 and state[i][j] != final_state[i][j]:
          h_state += 1

  return h_state

# Manhattan distance heuristic
def h3(state, final_state, empty_tile):
  h_state = 0
  final_pos = [[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0],[0,0]]
  for i in range(3):
    for j in range(3):
      final_pos[final_state[i][j]][0] = i
      final_pos[final_state[i][j]][1] = j

  for i in range(3):
    for j in range(3):
      if(empty_tile):
        h_state += abs(final_pos[state[i][j]][0] - i) + abs(final_pos[state[i][j]][1] - j)
      elif state[i][j]!=0:
        h_state += abs(final_pos[state[i][j]][0] - i) + abs(final_pos[state[i][j]][1] - j)
  
  return h_state

# Custom heuristic h(n) > h∗(n)
def h4(state, final_state, empty_tile):
  return h2(state, final_state, empty_tile)*h3(state, final_state, empty_tile)