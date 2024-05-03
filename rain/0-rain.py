"""

Prototype: def rain(walls)

Given a list of non-negative integers representing the heights
of walls with unit width 1, as if viewing the cross-section of
a relief map, calculate how many square units of water will be
retained after it rains.
walls is a list of non-negative integers.
Return: Integer indicating total amount of rainwater retained.
Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls,
meaning they will not retain water.
If the list is empty return 0.

"""
def rain(walls):
    wall_1 = 0
    wall_2 = 0
    width = 0
    total = 0
    for item in walls:
        if (item == 0) and (wall_1 > 0):
            width += 1
        if item > 0:
            if wall_1 == 0:
                wall_1 = item
            else:
                wall_2 = item
                total += wall_1 * width if wall_1 < wall_2 else wall_2 * width
                wall_1 = wall_2
                wall_2 = width = 0
    return total
            
