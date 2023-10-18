'''
Project Euler #28: Number spiral diagonals - Easy

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:
  21  22  23  24  25
  20   7   8   9  10
  19   6   1   2  11
  17  16  15  14  13  
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a NxN, (N is odd) spiral formed in the same way?
As the sum will be huge you have to print the result mod (10^9+7)

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=10^5
1<=N<=10^18,N is odd

Output Format
Print the values corresponding to each test case.

Sample Input
2
3
5

Sample Output

25
101
'''

# # Try 1: TC:3/5 Rest TLE error
# # Enter your code here. Read input from STDIN. Print output to STDOUT
# for _ in range(int(input())):
#     n=int(input())
#     ptr=3
#     diff=2
#     sum=1
#     count=0
#     while (ptr<=n*n):
#         sum+=2*(2*ptr+3*diff)
#         ptr+=3*diff
#         diff+=2
#         ptr+=diff
#     print(sum%(10**9+7))

# Try 2: TC 5/5
'''
Idea: Create O(1) solution by considering the patterns in the diagonal elements in the spiral matrix

For example take this 5 * 5 box

21 22 23 24 25
20 07 08 09 10
19 06 01 02 11
18 05 04 03 12
17 16 15 14 13

The numbers on the upper right diagonal are squares of natural numbers.

Well, all these number are squares –
1^2 = 1
3^2 = 9
5^2 = 25
7^2 = 49

Considering the distance of the number from the center of the spiral as a parameter, this series can be written as:
d1 = (2n + 1) ^2 Hence d1 = 4n^2 + 4n + 1

The numbers along the other diagonals are simply derived from d1 by subtracting certain values.
d2 = d1 - 2n Hence d2 = 4n^2 + 2n + 1
d3 = d2 - 2n Hence d3 = 4n^2 + 1
d4 = d3 - 2n Hence d4 = 4n^2 - 2n + 1

Now, all that the problem asks us to do is to sum up the numbers d1, d2, d3, d4 for n = 1, 2, 3, . . . . .. . ..
Required sum = summation of (16n^2 + 4n + 4) for n = 1, 2, 3, . . . . .
= Summation (16n^2 + 4n + 4) (for n=1 to N) 
= Sigma(for n=1 to N) (16n^2 + 4n + 4)  
= 16 Sigma(n^2) + 4 Sigma(n) + 4 Sigma(1)
 
Since,
Summation of n^2 (for n=1 to N) = N(N+1)(2N+1) /6
Summation of n   (for n=1 to N) = N(N+1) /2
Summation of 1   (for n=1 to N) = N

Required sum = 16 [N(N+1)(2N+1) /6] + 4 [N(N+1) /2] + 4 [N]
= (16N^3 + 30N^2 + 26N + 3 ) / 3

'''
# Enter your code here. Read input from STDIN. Print output to STDOUT
for _ in range(int(input())):
    n=int(input())
    n=(n-1)//2
    sum = (16*n**3+30*n**2+26*n+3)//3
    print(sum % (10**9+7))


