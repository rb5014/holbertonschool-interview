#!/usr/bin/python3
"""Write a script that reads stdin line by line and computes metrics:

Input format:
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" \
<status code> <file size> (if the format is not this one,
the line must be skipped)
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous <file size>
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear or is not an integer,
don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order
"""


tot_file_size = 0
status_dict = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}
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
