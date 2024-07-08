# Making Change

This project provides a solution to the problem of determining the fewest number of coins needed to meet a given amount total, using a list of coins of different values.

## Project Overview

The purpose of this project is to implement an algorithm that finds the minimum number of coins needed to make up a specified total. This is a classic problem in computer science and can be approached using dynamic programming or greedy algorithms, depending on the coin denominations.

## Files and Their Purposes

### 1. `0-making_change.py`
- **Purpose**: Contains the implementation of the `makeChange` function, which determines the fewest number of coins needed to meet a given total.
- **Function**: `def makeChange(coins, total)`
  - **Parameters**:
    - `coins`: List of the values of the coins in your possession.
    - `total`: The amount total that needs to be met.
  - **Returns**:
    - The fewest number of coins needed to meet the total.
    - `0` if the total is `0` or less.
    - `-1` if the total cannot be met by any number of coins in possession.

### 2. `0-main.py`
- **Purpose**: Main file for testing the `makeChange` function.
- **Usage**: Runs example test cases to demonstrate the functionality of the `makeChange` function.

## Function Details

### `makeChange(coins, total)`
- **Description**: This function calculates the minimum number of coins required to meet a given total using the available coin denominations.
- **Algorithm**:
  - If the total is `0` or less, return `0`.
  - If the total cannot be met by any number of coins, return `-1`.
  - Otherwise, compute the minimum number of coins needed.
- **Example Usage**:
  ```python
  makeChange([1, 2, 25], 37)  # Output: 7
  makeChange([1256, 54, 48, 16, 102], 1453)  # Output: -1
