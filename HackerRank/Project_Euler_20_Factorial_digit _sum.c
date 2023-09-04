/*Project Euler #20: Factorial digit sum
n!=nx(n-1)x...x3x2x1
For example, 10!=10x9x...x3x2x1=3628800,
and the sum of the digits in the number 10! is 3+6+2+8+8+0+0=27.
Find the sum of the digits in the number N!

Input Format
The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=100
0<=N<=1000

Output Format
Print the values corresponding to each test case.

Sample Input

2
3
6

Sample Output
6
9

Explanation

3! is 6, sum of digit is 6.
6! is 720, sum of digits is 9.
*/

/*
# Try 1 in Python: 4/4 TC passed. Score:100/100
# Enter your code here. Read input from STDIN. Print output to STDOUT
for _ in range(int(input())):
    n=int(input())
    p=1
    for i in range(1,n+1):
        p*=i
    sd=0
    while(p>0):
        sd+=p%10
        p=p//10
    print(sd,end="\n");
*/

