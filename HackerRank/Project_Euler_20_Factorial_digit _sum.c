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

//Try 2 in C: 4/4 TC passed. Score:100/100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Multiply number stored as array with integer = array*num.
// e.g.789*10=7890 => {9,8,7}*10={0,9,8,7}
int multiply(int *array,int arraysize,int num)
{   int carry=0;
    for(int i=0;i<arraysize;i++)
    {   int temp=array[i]*num + carry;
        array[i]=temp%10;
        carry=temp/10;
    }
    while(carry>0)    
    {   array[arraysize++]=carry%10;
        carry=carry/10;
    }
    return arraysize;
}
int main() {
    int t,n;  scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   scanf("%d",&n);
        int *fac=malloc(2600*sizeof(int)); //no of digits in 1000! is 2568 digits
        fac[0]=1; int facsize=1;
        for(int i=1;i<=n;i++)
            facsize=multiply(fac,facsize,i);
        int sd=0;
        for(int i=0;i<facsize;i++)
            sd+=fac[i];
        printf("%d\n",sd);
    }
    return 0;
}


