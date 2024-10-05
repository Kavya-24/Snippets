def print_board(board):
    for row in board:
        print(" ".join("Q" if cell else "." for cell in row))
    print()

def is_safe(board, row, col):
    for i in range(row):
        if board[i][col]:
            return False

    i, j = row, col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1

    i, j = row, col
    while i >= 0 and j < len(board):
        if board[i][j]:
            return False
        i -= 1
        j += 1

    return True

def solve_queens(board, row, solutions):
    if row >= len(board):
        solutions.append([row[:] for row in board])  
        return

    for col in range(len(board)):
        if is_safe(board, row, col):
            board[row][col] = True
            solve_queens(board, row + 1, solutions)
            board[row][col] = False

def eight_queens():
    size = int(input("Enter size of the board: "))
    while (size < 0):
        print("Please enter a positive number! ")
        size = int(input("Enter size of the board: "))

    board = [[False for _ in range(size)] for _ in range(size)]
    solutions = []
    solve_queens(board, 0, solutions)
    
    if not solutions:
        print("No solution exists.")
    else:
        print(f"Found {len(solutions)} solutions:")
        for i, solution in enumerate(solutions):
            print(f"Solution {i + 1}:")
            print_board(solution)

eight_queens()
