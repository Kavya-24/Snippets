import sys
import collections
import itertools
import heapq
import bisect
import math
from functools import lru_cache
from collections import defaultdict, deque, Counter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations

# Fast input/output
input = sys.stdin.read
output = sys.stdout.write

# Utility functions
def ii():
    """Reads a single integer."""
    return int(input().strip())

def mi():
    """Reads multiple integers."""
    return map(int, input().strip().split())

def lmi():
    """Reads a list of multiple integers."""
    return list(map(int, input().strip().split()))

def si():
    """Reads a single string."""
    return input().strip()

def solve():
    # Main logic for each test case/problem goes here
    pass

def main():
    # Uncomment the line below for handling multiple test cases
    # t = ii()  # Read the number of test cases
    # for _ in range(t):
    solve()  # Call solve function for each test case/problem

if __name__ == "__main__":
    # Uncomment the next line to use fast input in a local environment
    # sys.stdin = open("input.txt", "r")
    main()
