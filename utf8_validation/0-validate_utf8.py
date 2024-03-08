#!/usr/bin/python3

"""
Method to validate a UTF8 set of data
"""

def validUTF8(data):
    """
    Check the 8 least significant bits (LSBs)
    Vefify if given data represents valid UTF-8 encoding

    data: list of integers

    Returns:
        True if valid UTF-8 encoding, otherwise False
    """
    for char in data:
        if char > 255:
            return False
    return True;