'''
Flipping the Matrix

Sean invented a game involving a 2n x 2n matrix where each cell of the matrix contains an integer. He can reverse any of its rows or columns any number of times. The goal of the fame is to maximize the sum of the elements in the nxn submatrix located in te upper-left quadrant of the matrix. 
Given the initial configurations for q matrices, help Sean reverse the rows and columns of each matrix in the best possible way so that the sum of the elements in the matrix's upper-left quadrant is maximal.

Example
matrix=[[1,2],[3,4]]
1 2
3 4
It is 2x2 and we want to maximize the top left quadrant, a 1x1 matrix. Reverse row 1:
1 2 
4 3
And now reverse column 0:
4 2
1 3
The maximal sum is 4.

Function Description
Complete the flippingMatrix function in the editor below.
flippingMatrix has the following parameters:
  -int matrix[2n][2n]: a 2-dimensional array of integers
Returns
  -int: the maximum sum possible.

Input Format
The first line contains an integer q, the number of queries.
The next q sets of lines are in the following format:
The first line of each query contains an integer, n.
Each of the next 2n lines contains 2n space-separated integers matrix[i][j] in row i of the matrix.

Constraints
1<=q<=16
1<=n<=128
0<=matrix[i][j]<=4096,where 0<=i,j<=2n

Sample Input
STDIN            Function
-----            ---------
1                q=1
2                n=2
112 42 83 119    matrix=[[112,42,83,119], [56, 125, 56, 49], [15, 78, 101, 43], [62, 98, 114, 108] 
56 125 56 49
15 78 101 43
62 98 114 108

Sample Output
414

Explanation
Start out with the 2nx2n matrix. Perform the following operations to maximize the sum of the nxn submatrix in the upper-left quadrant:
Reverse column2: matrix = 
  112 42 114 119    
  56 125 101 49
  15 78 56 43
  62 98 83 108
Reverse row0: matrix = 
  119 114 42 112    
  56 125 101 49
  15 78 56 43
  62 98 83 108
Sum of values in the nxn submatrix in the upper-left quadrant is 119+114+56+125 = 414

Score:100
Clue got from: https://www.blogoncode.com/2022/08/flipping-matrix-solution-in-java.html
'''


#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'flippingMatrix' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY matrix as parameter.
#

def flippingMatrix(matrix):
    # Write your code here
    n=len(matrix)
    sum=0
    for i in range(n//2):
        for j in range(n//2):
            sum+=max(matrix[i][j], matrix[i][n-1-j], matrix[n-1-i][j], matrix[n-1-i][n-1-j])
    return sum    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    q = int(input().strip())
    for q_itr in range(q):
        n = int(input().strip())
        matrix = []
        for _ in range(2 * n):
            matrix.append(list(map(int, input().rstrip().split())))
        result = flippingMatrix(matrix)
        fptr.write(str(result) + '\n')
    fptr.close()
