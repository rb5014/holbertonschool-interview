#!/usr/bin/python3
import copy

"""
Given an n x n 2D matrix, rotate it 90 degrees clockwise.

Prototype: def rotate_2d_matrix(matrix):
Do not return anything. The matrix must be edited in-place.
You can assume the matrix will have 2 dimensions and will not be empty.
"""
def rotate_2d_matrix(matrix):

    tmp = copy.deepcopy(matrix)
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            tmp[i][j] = matrix[len(matrix) - j - 1][i]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = tmp[i][j]