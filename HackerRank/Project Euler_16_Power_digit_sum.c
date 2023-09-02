/*Project Euler #16: Power digit sum
2^9=512 and the sum of its digits is 5+1+2=8.
What is the sum of the digits of the number 2^N?

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=100
1<=N<=10^4

Output Format
Print the values corresponding to each test case.

Sample Input
3
3
4
7

Sample Output
8
7
11

Explanation
2^3=8, sum of digits is 8.
2^4=16, sum of digits is 7.
2^7=128, sum of digits is 11.
*/

/*
#Try 1 in Python. 10/10. Score:100
# Enter your code here. Read input from STDIN. Print output to STDOUT
for i in range(int(input())):
    n=int(input())
    num=2**n
    sd=0
    while(num>0):
        sd+=num%10
        num=num//10
    print(sd,end="\n")
*/

//Try 2 in C. 1/10. TC#1-9:Wrong answer
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;scanf("%d",&t);
    for (int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        int num=(int)pow(2,n);
        int sd=0;
        while(num>0)
        {   sd+=num%10;
            num=num/10;
        }
        printf("%d\n",sd);  
    }
    return 0;
}



