'''Project Euler #15: Lattice paths
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

Grid 2x2:
 __ __
|__|__|
|__|__|

Paths possible here from top left to bottom right corner:
__ __     __        __                            
     |      |__       |      |__ __      |__      |
     |         |      |__          |        |__   |__ __
     
How many such routes are there through a NxM grid? As number of ways can be very large, print it modulo (10^9+7).

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain integers N and M.

Constraints
1<=T<=1000
1<=N<=500
1<=M<=500

Output Format
Print the values corresponding to each test case.

Sample Input
2
2 2
3 2

Sample Output
6
10

Explanation
For 2x2 as shown in statement above.
'''

#Try 1: 11/11. Score:100
# Enter your code here. Read input from STDIN. Print output to STDOUT
from math import factorial
for _ in range(int(input())):
    n,m=map(int,input().split())
    print ((factorial(n+m)//factorial(m)//factorial(n))%(10**9+7))

#Try 2 in C
