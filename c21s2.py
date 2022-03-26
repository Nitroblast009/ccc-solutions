# Problem: Modern Art

# Get artist input:
rows = int(input())
cols = int(input())
board = [[0] * cols for row in [None] * rows]
strokeCount = int(input())

# Stroke magic:
sqCount = 0
for n in range(0, strokeCount):
    stroke = input().split()
    stroke[1] = int(stroke[1])
    if stroke[0] == "R":
        strokeRow = board[stroke[1] - 1]
        for colNumber in range(0, len(strokeRow)):
            if strokeRow[colNumber] == 0:
                strokeRow[colNumber] = 1
                sqCount += 1
            else:
                strokeRow[colNumber] = 0
                sqCount -= 1
    else:
        strokeCol = stroke[1] - 1
        for rowNumber in range(0, len(board)):
            if board[rowNumber][strokeCol] == 0:
                board[rowNumber][strokeCol] = 1
                sqCount += 1
            else:
                board[rowNumber][strokeCol] = 0
                sqCount -= 1

# Print total painted squares count:
print(sqCount)