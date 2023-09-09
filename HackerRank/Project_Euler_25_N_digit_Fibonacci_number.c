/*Project Euler #25: N-digit Fibonacci number -  EASY
The Fibonacci sequence is defined by the recurrence relation:
  Fn=Fn-1+Fn-2, where F1=1 and F2=1.
Hence the first 12 terms will be: F1=1  F2=1 F3=2 F4=3 F5=5 F6=8 F7=13 F8=21 F9=34 F10=55 F11=89 F12=144
The 12th term, F12, is the first term to contain three digits.
What is the first term in the Fibonacci sequence to contain N digits?

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=5000
2<=N<=5000

Output Format

Print the values corresponding to each test case.

Sample Input

2
3
4
Sample Output

12
17
*/

//Try 1: TC:2/4 Rest failed due to Time Limit Exceeded.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main() {
    int t;  scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;   scanf("%d",&n);
        unsigned long long a=1,b=1,c=1;int count=2;
        unsigned long long nd=(log10(c)+1);//printf("nd=%d ",nd);
        while(nd<n)
        {   c=a+b;count++;//printf("c=%d ",c);
            nd=(log10(c)+1);
            a=b;b=c;
        }
        printf("%d\n",count);
    }
    return 0;
}
