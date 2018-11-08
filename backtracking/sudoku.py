from itertools import *
from copy import copy

def is_distinct(list):
    used = []
    for i in list:
        if i == 0:
            continue
        if i in used:
            return False
        used.append(i)
    return True

def is_valid(brd):
    for i in range(3):
        row = [brd[i][0], brd[i][1], brd[i][2]]
        if not is_distinct(row):
            return False
        col = [brd[0][i], brd[1][i], brd[2][i]]
        if not is_distinct(col):
            return False
    return True

def solve(brd, empties = 9):
    if empties == 0:
        return is_valid(brd)
    for row, col in product(range(3), repeat=2):
        cell = brd[row][col]
        if cell != 0:
            continue
        brd2 = copy(brd)
        for test in [1, 2, 3]:
            brd2[row][col] = test
            if is_valid(brd2) and solve(brd2, empties-1):
                return True
            brd2[row][col] = 0
    return False

Board = [
        [0, 0, 0],
        [1, 0, 0],
        [0, 3, 1]
        ]

solve(Board, 9 - 3)

for row in Board:
    print row
