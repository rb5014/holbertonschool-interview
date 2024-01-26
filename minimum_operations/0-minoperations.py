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
    if n <= 0:
        return 0

    # Init an array to store the minimum number of operations for each number
    dp = [float('inf')] * (n + 1)

    # Base case: It takes 0 operations to reach 1 H
    dp[1] = 0

    # Iterate from 2 to n to calculate the minimum operations for each number
    for i in range(2, n + 1):
        # Iterate from 1 to i // 2 to find the minimum operations
        for j in range(1, (i // 2) + 1):
            # If i is divisible by j, then we can copy j H characters
            # and paste (i // j - 1) times
            if i % j == 0:
                dp[i] = min(dp[i], dp[j] + i // j)

    return dp[n] if dp[n] != float('inf') else 0
