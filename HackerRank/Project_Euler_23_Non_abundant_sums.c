/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number  is called deficient if the sum of its proper divisors is less than  and it is called abundant if this sum exceeds .

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Given , print YES if it can be expressed as sum of two abundant numbers, else print NO.

Input Format

The first line contains an integer  , i.e., number of test cases.
Next  lines will contain an integer .

Constraints



Output Format

Print the values corresponding to each test case.

Sample Input

2
24
49
Sample Output

YES
NO
*/

//Try 1: 4/4 testcases passed
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pds(int num)
{   int sum=0;
    for(int i=1;i<=sqrt(num);i++)
    {   if(num%i==0)
        {   if (i!=num) sum+=i;
            if (i!=1 && num/i!=i)   sum+=num/i;
            if (sum>num)
                break;
        }
    }
    if (sum==num)   return 0;
    if (sum>num)    return 1;
    return -1;
}
int main() {
    int t,n;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   scanf("%d",&n);
        int i=1;
        for(i=1;i<=n/2;i++)
            if(pds(i)>0 && pds(n-i)>0)  {printf("YES\n");break;}
        if(i>n/2)
            printf("NO\n");
    }
    return 0;
}

