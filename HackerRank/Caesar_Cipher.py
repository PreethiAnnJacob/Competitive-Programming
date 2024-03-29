'''Caesar Cipher
Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's cipher shifts each letter by a number of letters. If the shift takes you pass the end of the alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x, y and z would map to z, a, b and c.
Original alphabet: abcdefghihklmnopqrstuvwxyz
Alphabet rotated +3: defghijklmnopqrstuvwxyzabc

Example
s = There's-a-starman-waiting-in-the-sky
k = 3
THe alphabet is rotated by 3, matching the mapping above. The encrypted string is Wkhuh'v-d-vwdupdq-zdlwlqj-lq-wkh-vnb.
Note: The cipher only encrypts letters; symbols, such as - remain unencrypted.

Function description
Complete the caesarCipher function in the editor below.
caesarCipher has the following parameters:
  strings:cleartext
  int k: the alphabet rotation factor
Returns
  string: the encrypted string

Input Format
The first line contains the integer, n, the length of the unencrypted string.
The second line contains the unencrypted string,s.
The third line contains k, the number of letters to rotate the alphabet by.

Constraints
1<=n<=100
0<=k<=100
s is a valid ASCII string without any spaces.

Sample Input
11
middle-Outz
2

Sample Output
okffng-Qwvb
'''
  
#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    # Write your code here
    ns=""
    for ch in s:
        if (ch.isalpha()):
            if (ch.islower()):
                ch= chr((((ord(ch)-ord('a'))+k)%26)+ord('a'))
            else:
                ch= chr((((ord(ch)-ord('A'))+k)%26)+ord('A')) 
        ns=ns+ch
    return ns
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input().strip())
    s = input()
    k = int(input().strip())
    result = caesarCipher(s, k)
    fptr.write(result + '\n')
    fptr.close()
