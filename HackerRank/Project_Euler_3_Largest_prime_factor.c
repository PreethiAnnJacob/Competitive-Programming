/*Project Euler #3: Largest prime factor
The prime factors of 13195 are 5,7,13 and 29.
What is the largest prime factor of a given number N?

Input Format
First line contains T, the number of test cases. This is followed by T lines each containing an integer N.

Constraints
1<=T<=10
10<=N<=10^12

Output Format
For each test case, display the largest prime factor of N.

Sample Input 0

2
10
17
Sample Output 0

5
17
Explanation 0

Prime factors of 10 are {2,5}, largest is 5.
Prime factor of 17 is 17 itself, hence largest is 17.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//Try 1: 5/6 testcases passed. Testcase #5 shows TimeLimitExceeded error.
// int main(){
//     int t; 
//     scanf("%d",&t);
//     long lpf[t];
//     for(int a0 = 0; a0 < t; a0++){
//         long n; 
//         scanf("%ld",&n);
//         lpf[a0]=1;
//         for(int i=n;i>=1;i--)
//         {   if(n%i==0)
//             {   int prime=1;
//                 for(int j=2;j<=sqrt(i);j++)
//                     if(i%j==0)  {prime=0;break;}
//                 if(prime==1)    {lpf[a0]=i;break;}
//             }
//         }
//     }
//     for(int a0 = 0; a0 < t; a0++)
//         printf("%ld\n",lpf[a0]);
//     return 0;
// }

//Try 2: Same 5/6 testcases passed. Testcases#6 shows TLE 
// int main(){
//     int t; 
//     scanf("%d",&t);
//     long lpf[t];
//     for(int a0 = 0; a0 < t; a0++){
//         long n; 
//         scanf("%ld",&n);
//         lpf[a0]=1;
//         for(int i=2;i<=n;i++)
//         {   if(n%i==0)
//             {   int prime=1;
//                 for(int j=2;j<=sqrt(i);j++)
//                     if(i%j==0)  {prime=0;break;}
//                 if(prime==1)
//                 {   lpf[a0]=i;
//                     n=n/i;                        //Introduced this idea. So i loop now traverse from front
//                 }
//             }
//         }
//     }
//     for(int a0 = 0; a0 < t; a0++)
//         printf("%ld\n",lpf[a0]);
//     return 0;
// }

//Try3 : Modified Try 1. Same result 5/6. Testcase #6 shows TLE
// int main(){
//     int t; 
//     scanf("%d",&t);
//     long lpf[t];
//     for(int a0 = 0; a0 < t; a0++){
//         long n; 
//         scanf("%ld",&n);
//         lpf[a0]=1;
//         for(int i=n;i>=1;i--)
//         {   if(n%i==0)
//             {   int prime=1;
//                 for(int j=2;j<=sqrt(i);j++)
//                     if(i%j==0)  {prime=0;break;}
//                 if(prime==1)    {lpf[a0]=i;break;}
//                 n=i;                                    //Changed here
//             }
//         }
//     }
//     for(int a0 = 0; a0 < t; a0++)
//         printf("%ld\n",lpf[a0]);
//     return 0;
// }

