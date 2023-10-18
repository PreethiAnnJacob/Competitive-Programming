/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than  which divide evenly into n).
If d(a)=b and d(b)=a, where a!=b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1,2,4,5,10,11,20,22,44,55 and 110 therefore d(220)=284. The proper divisors of 284 are 1,2,4,71 and 142 so d(284)=220.

Evaluate the sum of all the amicable numbers under N.

Input Format

The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=1000
1<=N<=10^5

Output Format

Print the values corresponding to each test case.

Sample Input

1
300
Sample Output

504
Explanation

Under 300 we only have 220 and 284, sum is 504.
*/

//Try 1: 4/4. Score:100/100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pds[100001]={};
int properDivisorSum(int num)
{   if (num==1) return 0;
    int sum=0;
    for(int i=1;i<=sqrt(num);i++)
    {   if(num%i==0)    
        {   sum+=i;
            if (num/i!=i && i!=1) //So that we don't add num itself and twins
                sum+=(num/i);
        }
    }
    return sum;
}
int main() {
    int limit =100000;
    for(int i=1;i<=limit;i++)
        pds[i]=properDivisorSum(i);
    int t,n;  scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   scanf("%d",&n);
        int amicableSum=0;
        for(int i=1;i<=n;i++)
        {   if (pds[i]>=1 && i<pds[i]) // i<pds[i] so that repetition of pairs can be avoided
            {   int pdsPair = (pds[i]<=limit) ? pds[pds[i]] : properDivisorSum(pds[i]); //Check out in the precalculated map, else Go find it!
                if (pdsPair==i)
                {   amicableSum+=i;
                    if (pds[i]<=n)  amicableSum+=pds[i];  //Sum it up only if it falls between 1 and n
                }
            }
        }
        printf("%d\n",amicableSum);
    }
    return 0;
}
