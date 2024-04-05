#!/usr/bin/python3
import sys

"""The N queens puzzle is the challenge of placing N non-attacking queens
on an NxN chessboard. Write a program that solves the N queens problem.
Usage: nqueens N
If the user called the program with the wrong number of arguments,
print Usage: nqueens N, followed by a new line, and exit with the status 1
where N must be an integer greater or equal to 4
If N is not an integer, print N must be a number, followed by a new line, and exit with the status 1
If N is smaller than 4, print N must be at least 4, followed by a new line, and exit with the status 1
The program should print every possible solution to the problem
One solution per line
Format: see example
You don't have to print the solutions in a specific order
You are only allowed to import the sys module
"""

def queens(n: int, i: int, a: list, b: list, c: list):
    if i < n:
        for j in range(n):
            if j not in a and i + j not in b and i - j not in c:
                yield from queens(n, i + 1, a + [j], b + [i + j], c + [i - j])
    else:
        a = [[i, a[i]] for i in range(0, n)]
        yield a

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
try:
    n = int(sys.argv[1])
    if n < 4:
        print("N must be at least 4")
        exit(1)
except ValueError:
    print("N must be a number")
    exit(1)



for solution in queens(n, 0, [], [], []):
    print(solution)

