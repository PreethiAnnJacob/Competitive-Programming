/* Project Euler #1: Multiples of 3 and 5
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below N.

Input Format

First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1<=T<=10^5
1<=N<=10^9

Output Format

For each test case, print an integer that denotes the sum of all the multiples of 3 or 5 below N.

Sample Input 0

2
10
100

Sample Output 0

23
2318
Explanation 0

For N=10, if we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3,5,6 and 9. The sum of these multiples is 23.

Similarly for N=100, we get 2318.
*/


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//Try 1:  4/6 testcases passed. 2 testcases show time limit exceeded error. O(n) time complexity
// int main(){
//     int t; 
//     scanf("%d",&t);
//     int sum[100000];
//     for(int a0 = 0; a0 < t; a0++){
//         int n; 
//         scanf("%d",&n);
//         sum[a0]=0;
//         for(int i=3;i<n;i++)
//         {   if(i%3==0 || i%5==0)
//             {   sum[a0]+=i;
//             }
//         }
//     }
//     for(int a0 = 0; a0 < t; a0++)
//     {   printf("%d\n",sum[a0]);
//     }   
//     return 0;
// }

// Try 2: 6/6 testcases passed. Constant time complexity. Note: If int is used in anywhere instead of long, the same 2 testcases from Try 1 shows Wrong answer error
int main(){
    int t; 
    scanf("%d",&t);
    long sum[100000];
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        long s3=0,s5=0,s15=0;
        //printf("n=%d ",n);
        n=n-1;
        if (n>=3)
        {   long l3=n-(n%3);//printf("l3=%d ",l3);
            s3=(l3*(l3+3))/6;//printf("s3=%d ",s3);
            if (n>=5)
            {   long l5=n-(n%5);//printf("l5=%d ",l5);
                s5=(l5*(l5+5))/10;//printf("s5=%d ",s5);
                if (n>=15)
                {   long l15=n-(n%15);//printf("l15=%d ",l15);
                    s15=(l15*(l15+15))/30;//printf("s15=%d ",s15);
                }
            }
            // printf("\n");
        }
        sum[a0]=s3+s5-s15;
    }
    for(int a0 = 0; a0 < t; a0++)
    {   printf("%ld\n",sum[a0]);
    }   
    return 0;
}
