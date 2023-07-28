# Given an array of integers, where all elements but one occur twice, find the unique element.
# Example: array = [1,2,3,4,3,2,1]
# The unique element is 4
# It is guaranteed that number of integers is an odd number and that there is one unique element.

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'lonelyinteger' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def lonelyinteger(a):
    # Write your code here
    a.sort()
    output=a[-1] 
    for i in range(0,len(a)-1,2):
        if (a[i]!=a[i+1]):
            output=a[i]
            break
    return output

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = lonelyinteger(a)

    fptr.write(str(result) + '\n')

    fptr.close()
