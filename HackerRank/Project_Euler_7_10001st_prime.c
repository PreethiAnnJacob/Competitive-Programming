/*Project Euler #7: 10001st prime
By listing the first six prime numbers: 2,3,5,7,11,13 and , we can see that the 6th prime is 13.
What is the Nth prime number?

Input Format

First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1<=T<=10^3
1<=N<=10^4

Output Format

Print the required answer for each test case.

Sample Input 0

2
3
6
Sample Output 0

5
13
Explanation 0

The first 10 prime numbers are {2,3,5,7,13,17,19,23,29}

we can see that 3rd prime number is 5 and 6th prime number is 13 
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//Try1: 3/5 testcases passed. TC#3 and#4 shows TLE
// int main(){
//     int t; 
//     scanf("%d",&t);
//     for(int a0 = 0; a0 < t; a0++){
//         int n; 
//         scanf("%d",&n);
//         int num=2;
//         int count=0;
//         while(count<n) 
//         {   int prime=1;
//             for(int i=2;i<=sqrt(num);i++)
//                 if(num%i==0)    {prime=0;break;}
//             if (prime==1)   count++;
//             if(count==n)    printf("%d\n",num);
//             num++;      
//         }
//     }
//     return 0;
// }

//Try 2: 4/5 testcases passed. TC#4 TLE
// int main(){
//     int t; 
//     scanf("%d",&t);
//     for(int a0 = 0; a0 < t; a0++){
//         int n; 
//         scanf("%d",&n);
//         if (n==1)   printf("2\n");
//         else
//         {   int num=3;
//             int count=1;
//             while(count<n) 
//             {   int prime=1;
//                 for(int i=3;i<=sqrt(num);i=i+4)
//                     if(num%i==0 | num%(i+2)==0)    {prime=0;break;}
//                 if (prime==1)   count++;
//                 if(count==n)    printf("%d\n",num);
//                 num=num+2;      
//             }
//         }
//     }
//     return 0;
// }

//Try 3: 5/5 testcases passed.
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        if (n==1)   printf("2\n");
        else if (n==2)   printf("3\n");
        else
        {   int num=5;                                     //since we know the next prime number is 5
            int count=2;                                   //since we already have 2 prime numbers ready i.e. 2 and 3.
            while(count<n) 
            {   int prime=1;
                if (num%3==0) prime=0;                     //instead of "if (num%2==0 || num%3==0) prime=0;". Since only prime numbers less than 5 is 2 and 3. We have skipped the chances of even numbers by incrementing num by 2    
                else
                {   for(int i=5;i*i<=num;i=i+6)            //Any prime number>3 can be expressed as 6k+1 or 6k-1(~6k+5). So to check if num is prime or not, instead of checking any num from 1 to num is a factor of num, we are checking if num has any prime factor
                        if(num%i==0||num%(i+2)==0)         //Checking for (6k+5)~(6k-1) and (6k+7)~(6k+1)  
                        {    prime=0;
                             break;
                        }
                }
                if (prime==1)   count++;
                if(count==n)    printf("%d\n",num);
                num=num+2;//Increment by 2 to avoid checking whether even numbers are prime    
            }
        }
    }
    return 0;
}

