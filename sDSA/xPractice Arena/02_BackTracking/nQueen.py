# Solve for 3x3 queen
#todo: Min n is 4;
"""
this is running like 
    ["q1...", 
     "q2...", 
     "q3...",
     "q4..."]
"""
from typing import List

"""
This will give ["....", "....", "....", "...."]
"""
# board Generator
def generateBoard(count: int)-> List[str]:
    board = []
    for _ in range(1,count+1):
        oneRow = ""
        for _ in range(1,count+1):      # or just even do {onerow = '.' * count} !!
            oneRow += "."
        board.append(oneRow)
    return board

def isSafe(board, row, col):
    n = len(board)
    # Check Horizontally
    for j in range(row):
        if board[j][col] == 'Q':
            return False

    # upper Left
    i, j = row - 1, col - 1
    while i >= 0 and j >= 0:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j -= 1

    # Upper Right
    i, j = row - 1, col + 1
    while i >= 0 and j < n:
        if board[i][j] == 'Q':
            return False
        i -= 1
        j += 1

    return True

# backtrack Fuction
def solveQueenBack(board: List[str], solution: List[List[str]], row: int, nQueens: int):
    if row == len(board): # or nQueen
        solution.append(board.copy())
        #? .append(["".join(r) for r in board])
        return
    
    for col in range(nQueens): # NOTE: 0 -> 3
        if isSafe(board, row, col): 
            # this i is traversing throungh the list
            # and col is traversing thrung string[i]
            board[row] = board[row][:col] + "Q" + board[row][col+1:]
            solveQueenBack(board, solution, row+1, nQueens)
            board[row] = board[row][:col] + "." + board[row][col+1:] #todo : Backtrack
    return #todo : Backtrack

"""
solution will change in base case of BackTracking Fuction
"""
#* helperFunction
def solveQueen(nQueens: int)-> List[List[str]]:
    board = generateBoard(nQueens)
    solution = []
    solveQueenBack(board,solution,0, nQueens)
    return solution

#* Main
nQueens = 4
solutions = solveQueen(nQueens)

if 0 == len(solutions):
    print("No sol")
else:
    for s in solutions:
        print(s)

