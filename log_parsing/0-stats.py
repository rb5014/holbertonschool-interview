#!/usr/bin/python3

"""
Module 0-stats
Exercice Log parsing
"""
import traceback
import sys


def main():
    """
    main
    """

    tot_file_size = 0

    # Dictionary status codes
    status_dict = {'200': 0,
                   '301': 0,
                   '400': 0,
                   '401': 0,
                   '403': 0,
                   '404': 0,
                   '405': 0,
                   '500': 0}
    try:
        count = 0
        while 1:
            count += 1
            input_string = input()
            sep_string = input_string.split(" ")
            if len(sep_string) < 2:
                continue
            # Add filesize to total size
            tot_file_size += int(sep_string[-1])
            if sep_string[-2] in status_dict.keys():
                # Increment the count for the respective status code
                status_dict[sep_string[-2]] += 1

            # Print each ten lines
            if count == 10:
                count = 0
                print_info(tot_file_size, status_dict)
    except:
        """ Keyboard interruption """
        print_info(tot_file_size, status_dict)


def print_info(tot_file_size, status_dict):
    """ print_info """
    print("File size: " + str(tot_file_size))
    for status in sorted(status_dict.keys()):
        if status_dict[status] > 0:
            print("{}: {}".format(status, status_dict[status]))


if __name__ == "__main__":
    main()
