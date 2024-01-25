#!/usr/bin/python3

"""In a text file, there is a single character H.
 Your text editor can execute only two operations in this file:
 Copy All and Paste. Given a number n, write a method that calculates
 the fewest number of operations needed to result in exactly n H characters
 in the file. Be smart about how you utilize the memory!

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
Example:

n = 9

H => Copy All => Paste => HH => Paste =>HHH => Copy All =>
Paste => HHHHHH => Paste => HHHHHHHHH

Number of operations: 6
"""


def minOperations(n):
    copy_all_n = 1
    paste_n = 1
    current_n = 1
    op_number = 0

    while (1):
        if (current_n >= n):
            break
        if (current_n + copy_all_n <= n):
            current_n += copy_all_n
            paste_n = copy_all_n
            copy_all_n = current_n
            op_number += 2
        elif (current_n + paste_n <= n):
            current_n += paste_n
            op_number += 1

    return op_number
