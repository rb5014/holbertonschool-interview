#!/usr/bin/python3
def canUnlockAll(boxes):
	"""You have n number of locked boxes in front of you.
	Each box is numbered sequentially from 0 to n - 1 and
 	each box may contain keys to the other boxes.
  
	All keys will be positive integers.
	There can be keys that do not have boxes.
 
	The first box boxes[0] is unlocked>
 
	Args:
		boxes (list): list of lists
  
	Return: True if all boxes can be opened, else return False
	"""
	# Try to validate each key except 0
	for key in range(1, len(boxes)):
		flag = False
		# Iterate through all boxes
		for box in range(len(boxes)):
			# If box contain the current key and isn't the current box
			if key in boxes[box] and box != key:
				flag = True
				break
		# Key wasn't found in another box
		if not flag:
			return False

	# Each keys have been found in another box, so all boxes could be read
	return True
