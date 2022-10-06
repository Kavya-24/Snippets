# Importing python packages
import numpy as np

# Importing BFS Algo
from bfs import use_bfs

# Importing DFS Algo
from dfs import use_dfs

if __name__ == "__main__":
  # Zero is taken as the blank one
  initial_state = np.arange(9)
  np.random.shuffle(initial_state)
  initial_state = initial_state.reshape(3, -1)

  # Final State
  final_state = np.array([1,2,3,4,5,6,7,8,0]).reshape(3,-1)

  # Using BFS Algo
  use_bfs(initial_state, final_state)

  # Using DFS Algo
  use_dfs(initial_state, final_state)