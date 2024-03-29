'''Project Euler #13: Large sum
Work out the first ten digits of the sum of N 50-digit numbers.

Input Format
First line contains N, next N lines contain a 50 digit number each.

Constraints
1<=N<=10^3

Output Format
Print only first 10 digit of the final sum

Sample Input

5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
Sample Output

2728190129
Explanation

Summing the numbers we get 27271901298203036131464767301043585006837989465343, first 10 digits are 2727190129.
'''

# Try 1: 3/3 passed
# Enter your code here. Read input from STDIN. Print output to STDOUT
n=int(input())
sum=0
for i in range(n):
    num=int(input())
    sum=sum+num
print(str(sum)[:10])

# Try 2: in C: 0/3 cases passed. Wrong answer. Note: Value of sum is too much for any integer datatype to handle.

# Try 3: In C: 3/3 testcases passed.
# Idea : Consider the numbers as string. Sum two numbers = First Sum digitwise in reverse direction(Also,take care of carry). Now reverse that calculated sum. At last, show the first 10 digits.
