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
from math import sqrt

def minOperations(n):
    if n <= 1:
        return 0

    count = 0
    for i in range(2, int(sqrt(n) + 1)):
        while n % i == 0:  # i is a factor
            count += i
            n /= i
            if n <= 1:
                break
    if n > 1:
        count += int(n)
    return count

