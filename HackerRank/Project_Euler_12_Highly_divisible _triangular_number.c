/*Project Euler #12: Highly divisible triangular number - Easy

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 1: 4/8. TC#4#5,#6,#7 failed due to TLE
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
//     int t;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;
//         scanf("%d",&n);
//         int tn;
//         if(n<=0)    tn=1;
//         else if(n==1)   tn=3;
//         else
//         {   tn=3;                   //trianglenumber=3 if we already considered natural numbers 1,2
//             for(int i=3;i>-1;i++)   //i for natural number
//             {   tn=tn+i;
//                 int nf=2;
//                 for(int j=2;j<=tn/2;j++)
//                 {   if (tn%j==0)
//                     {   nf++;
//                         if(nf>n)    {i=-2;break;}  //Break from i and j loop
//                     }
//                 }
//             }
//         }
//         printf("%d\n",tn);
//     }      
//     return 0;
// }

//Try 2: 6/8. TC#6,#7 failed due to TLE. Modified Try 1 to change factor checking space from tn/2 to sqrt(tn)
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;
        scanf("%d",&n);
        int tn;
        if(n<=0)    tn=1;
        else if(n==1)   tn=3;
        else
        {   tn=3;   //trianglenumber=3 if we already considered natural numbers 1,2
            for(int i=3;i>-1;i++)   //i for natural number
            {   tn=tn+i;
                int nf=2;
                for(int j=2;j*j<=tn;j++)      //Change from Try1
                {   if (tn%j==0)
                    {   nf++;
                        if(tn/j!=j) nf++;     //Change from Try 1
                        if(nf>n)    {i=-2;break;}
                    }
                }
            }
        }
        printf("%d\n",tn);
    }  
    
    return 0;
}

