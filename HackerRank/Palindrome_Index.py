'''
Palindrome Index

Given a string of lowercase letters in the range ascii[a-z], determine the indices of a character that can be removed to make the string a palindrome. There may be more than one solution, but wny will do. If the word is already a palindrome or there is no solution, return -1. Otherwise, return the index of a character to remove.

Example
s="bcbc"
Either remove 'b' at index 0 or 'c' at index 3.

Function Description
Complete the palindromIndex function in the editor below.
palindromeIndex has the following parameters:
  string s: a string to analyze
Returns
  int: the index of the character to remove or -1

Input Format
The first line contains an integer q, the number of queries.
Each of the next q lines contains a query string s.

Constraints
1<=q<=20
1<=length og s<=10^5 +5
All characters are in the range ascii[a-z]

Sample Input
STDIN   FUNCTION
-----   --------
3       q=3
aaab    s='aaab' (first query)         
baa     s='baa' (second query)
aaa     s='aaa' (third query)

Sample Output
3
0
-1

Explanation
Query1:"aaab"
Removing 'b' at index 3 results in a palindrome, so return 3.
Query2:"baa"
Removing 'b' at index 0 results in a palindrome, so return 0.
Query 3: "aaa"
This string is already a palindrome, so return -1. Removing any one of the characters would result in a palindrome, but this test comes first.

'''

#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'palindromeIndex' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING s as parameter.
#

#-------------------------------------------------
# # Try1: Score:38.1/100
# # 7/15 testcases passed: 1 testcase failed with error. Rest failed due to time limit error

# def isPalindrome(num):
#     for i in range(len(num)//2):
#         if (num[i]!=num[len(num)-1-i]):
#             return False
#     return True

# def palindromeIndex(s):
#     # Write your code here
#     if (isPalindrome(s)):
#         return -1
#     for i in range(len(s)):
#         temp=s[0:i]+s[i+1:]
#         # print (s,temp)
#         if (isPalindrome(temp)):
#             return i
#---------------------------------------------------------------------

#---------------------------------------------------------------------------------
# # Try 2: 9/15 testcases passed. 1 wrong. Rest TLE

# def isPalindrome(num):
#     return (num==num[::-1])

# def palindromeIndex(s):
#     # Write your code here
#     if (isPalindrome(s)):
#         return -1
#     for i in range(len(s)):
#         temp=s[0:i]+s[i+1:]
#         # print (s,temp)
#         if (isPalindrome(temp)):
#             return i
#---------------------------------------------------------------------

#---------------------------------------------------------
# #Try 3:9/15 testcases passed

# def palindromeIndex(s):
#     # Write your code here
#     if (s!=s[::-1]):
#         for i in range(len(s)):
#             temp=s[:i]+s[i+1:]
#             if (temp==temp[::-1]):
#                 return i
#     return -1
#---------------------------------------------------------

#-------------------------------------------------------------------
# #Try 4: 10/15 testcases passed: Still 1 wrong. Rest TLE

# def palindromeIndex(s):
#     # Write your code here
#     if (s!=s[::-1]):
#         for i in range(len(s)//2):
#             temp=s[:i]+s[i+1:]
#             if (temp==temp[::-1]):
#                 return i
            
#             temp=s[:len(s)-1-i]+s[len(s)-i:]
#             if (temp==temp[::-1]):
#                 return (len(s)-1-i)
#     return -1
#-------------------------------------------------------------------

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    q = int(input().strip())
    for q_itr in range(q):
        s = input()
        result = palindromeIndex(s)
        fptr.write(str(result) + '\n')
    fptr.close()
