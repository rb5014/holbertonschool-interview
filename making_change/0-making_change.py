#!/usr/bin/python3
"""
Module 0-making_change.py
"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): A list of integers representing the values of the coins in your possession.
        total (int): The target amount to be met with the fewest number of coins.

    Returns:
        int: The minimum number of coins needed to meet the total.
             Returns 0 if the total is 0 or less.
             Returns -1 if the total cannot be met by any combination of the coins.

    Example:
        >>> makeChange([1, 2, 25], 37)
        7
        >>> makeChange([1256, 54, 48, 16, 102], 1453)
        -1
    """
    # If total is 0 or less, no coins are needed
    if total <= 0:
        return 0
    
    # Initialize dp array where dp[i] will be storing the minimum number of coins
    # required for amount i. We initialize with infinity as we don't know the minimum yet.
    dp = [float('inf')] * (total + 1)

    # Base case: No coins are needed to make 0 amount
    dp[0] = 0
 
     # Iterate over each coin
    for coin in coins:
        # Update dp array for all amounts that can be reached by the current coin
        for x in range(coin, total + 1):
            # If using the current coin results in a lesser number of coins, update dp[x]
            dp[x] = min(dp[x], dp[x - coin] + 1)

    # If dp[total] is still infinity, it means total cannot be met with given coins
    return dp[total] if dp[total] != float('inf') else -1
    

    
