# Given a time in -hour AM/PM format, convert it to military (24-hour) time.

# Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
# - 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    # Write your code here
    ampm=s[-2:]
    hh=int(s[:2])
    if (ampm=='AM' and hh==12):
        output='00'+s[2:8]
    elif (ampm=='AM' and hh!=12):
        output=s[:8]
    elif (ampm=='PM' and hh==12):
        output=s[:8]
    else:
        output=str(hh+12)+s[2:8]
    return output

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
