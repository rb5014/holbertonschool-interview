#!/usr/bin/python3

tot_file_size = 0
status_dict = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
count = 0
while 1:
    count += 1
    input_string = input()
    sep_string = input_string.split(" ")
    tot_file_size += int(sep_string[-1])
    if sep_string[-2] in status_dict.keys():
        status_dict[sep_string[-2]] += 1

    if count == 10:
        count = 0
        print("File size: " + str(tot_file_size))
        for status in sorted(status_dict.keys()):
            if status_dict[status] > 0:
                print("{}: {}".format(status, status_dict[status]))
                status_dict[status] = 0