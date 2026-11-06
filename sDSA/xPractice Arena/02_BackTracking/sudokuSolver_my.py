"""
Question : Solve Sudoku
    Assumptions :
        - 0 for the null
        - 1 to 9 to the inputs are valid
    Constrains :
        - 9x9 solve only
"""
# basic sudoku config
# 4x4 , 9x9, 16x16

                            #! CODE

"""
Sample Sudoku
paragrams: none
return: sudoku[][]
"""
def sampleSudoku() : #todo: Hard coded
    sudoku_easy = [
        [8, 0, 7, 9, 3, 0, 0, 0, 0],
        [0, 4, 6, 0, 0, 2, 0, 5, 0],
        [0, 0, 0, 0, 0, 8, 7, 0, 2],
        [0, 0, 9, 7, 5, 0, 6, 0, 8],
        [0, 0, 0, 0, 1, 0, 3, 0, 0],
        [4, 5, 0, 0, 0, 6, 0, 0, 0],
        [0, 0, 0, 0, 6, 0, 0, 9, 0],
        [0, 0, 3, 0, 2, 0, 1, 0, 0],
        [0, 8, 1, 5, 0, 0, 0, 0, 4]
    ]

    sudoku_medium = [
        [0, 0, 0, 2, 6, 0, 7, 0, 1],
        [6, 8, 0, 0, 7, 0, 0, 9, 0],
        [1, 9, 0, 0, 0, 4, 5, 0, 0],
        [8, 2, 0, 1, 0, 0, 0, 4, 0],
        [0, 0, 4, 6, 0, 2, 9, 0, 0],
        [0, 5, 0, 0, 0, 3, 0, 2, 8],
        [0, 0, 9, 3, 0, 0, 0, 7, 4],
        [0, 4, 0, 0, 5, 0, 0, 3, 6],
        [7, 0, 3, 0, 1, 8, 0, 0, 0]
    ]

    sudoku_hard = [
        [0, 2, 0, 6, 0, 8, 0, 0, 0],
        [5, 8, 0, 0, 0, 9, 7, 0, 0],
        [0, 0, 0, 0, 4, 0, 0, 0, 0],
        [3, 7, 0, 0, 0, 0, 5, 0, 0],
        [6, 0, 0, 0, 0, 0, 0, 0, 4],
        [0, 0, 8, 0, 0, 0, 0, 1, 3],
        [0, 0, 0, 0, 2, 0, 0, 0, 0],
        [0, 0, 9, 8, 0, 0, 0, 3, 6],
        [0, 0, 0, 3, 0, 6, 0, 9, 0]
    ]

    return sudoku_easy

# """
# Board Genrator 
# paragrams: dimentionOne(int)
# return: board[][]
# """
# def generateBoard(dimentionOne: int) : #todo : static null board
#     board = []
#     for _ in range(1, dimentionOne+1):
#         row = []
#         for _ in range (1, dimentionOne+1):
#             row.append(0)
#         board.append(row)
    
#     return board

"""
Safe Number to Input Finder in each block
paragrams: board[][], currRow(int), currCol(int), value(int)
return: bool
"""
def isCorrect(board, currRow, currCol, val):
    for i in range(0, len(board)):
        if board[currRow][i] == val: # check only that crow 1,9
            return False
        if board[i][currCol] == val: # check only that ccol 1,9
            return False
    
    # first row and col of grid
    gRow = (currRow//3)*3; 
    gCol = (currCol//3)*3; 

    # grid check
    for i in range(3):
        for j in range(3):
            if board[gRow + i][gCol + j] == val:
                return False
    return True
    
"""
#! recusive , backtracking and worst
Solve Sudoku
paragrams: board[][], row(int), col(int)
return: bool
"""
def sudokuSolve(board, row, col) :
    if row == len(board):
        #* when board is solved
        return True # so the all recursive call terminate successfully
    
    #  row, col+1      OR       row+1, 0
    next_row, next_col = (row, col + 1) if col < 8 else (row + 1, 0)

    # if we enconter an system numnber / const
    if board[row][col] != 0 :
        return sudokuSolve(board, next_row, next_col)

    for val in range (1 , 10) :
        if isCorrect(board, row, col, val):
            board[row][col] = val
            if sudokuSolve(board, next_row, next_col) : 
                return True
            board[row][col] = 0 
            
    return False

"""
Board Printer 
paragrams: board[][]
return: none
"""       
def printBoard(board):
    print(end="\n")
    for rowArr in board:
        print("| ", end = "")
        for element in rowArr:
            print(f"[{element}] ", end = "")
        print("|")
    print(end="\n")






#todo: main
dimentionOne = 9
board = sampleSudoku()

print("Initial Board >")
printBoard(board)

if sudokuSolve(board, 0, 0): #* a current ques board will always solve without a doubt
    print("Solved Board >")
    printBoard(board)
else:
    print("Incorrect board")
