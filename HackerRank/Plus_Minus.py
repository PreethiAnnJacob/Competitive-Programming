# Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction on a new line with  places after the decimal.
# Score : Passed all testcases

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    # Write your code here
    pos=neg=zero=0
    for i in arr:
        if i==0:
            zero+=1
        elif i>0:
            pos+=1
        else:
            neg+=1
    print ("{:.6f}".format(pos/len(arr)))
    print ("{:.6f}".format(neg/len(arr)))
    print ("{:.6f}".format(zero/len(arr)))
    

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
