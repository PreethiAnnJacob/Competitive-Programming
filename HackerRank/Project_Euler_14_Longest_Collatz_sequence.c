/* Project Euler #14: Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:
If n is even, n->n/2
If n is odd, n->3n+1

Using the rule above and starting with 13, we generate the following sequence:
13->40->20->10->5->16->8->4->2->1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number,<=N produces the longest chain? If many possible such numbers are there print the maximum one.

Note: Once the chain starts the terms are allowed to go above N.

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integers N.

Constraints
1<=T<=10^4
1<=N<=5x10^6

Output Format

Print the values corresponding to each test case.

Sample Input

3
10 
15
20
Sample Output

9
9
19
Explanation

Collatz sequence for n=9 is,
9->28->14->7->22->11->34->17->52->26->13->40->20->10->5->16->8->4->2->1
containing  steps and is the longest for n<=10
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 1: 5/13 passed. Testcase#5-12 shows TLE
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
//     int t;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;
//         scanf("%d",&n);
//         int maxcount=1,maxstart=1;
//         for(int i=n;i>=2;i--)
//         {   int count=1;//number itself
//             int seq=i;//printf("%d ",seq);
//             while(seq>1)
//             {   if(seq%2==0)    seq=seq/2; 
//                 else            seq=3*seq+1;        
//                 count++;//printf("%d ",seq);
//             }
//             if(count>maxcount)  {maxcount=count;maxstart=i;}
//             //printf("%d \n",count);
//         }
//         printf("%d\n",maxstart);
//     }   
//     return 0;
// }

//Try 2: 1/13 passed. Testcase#1-#12 shows wrong answer
// Fresh Idea: Create map initially for all possible values using recursion and memoization.
// int next(n)
// {   if (n%2==0) return (n/2);
//     else        return (3*n+1);
// }
// int countCollatz(int n, int n_max,int collatz[])
// {   if (n>n_max)        return (1+countCollatz(next(n),n_max,collatz));
//     if (collatz[n]==0)  collatz[n]=(1+countCollatz(next(n),n_max,collatz));
//     return collatz[n];
// }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
// 
//     int n_max=5*10^6;
//     int collatz[n_max+1];int longest[n_max+1];
//     for(int i=1;i<=n_max;i++)
//         collatz[i]=0;
// 
//     collatz[1]=1;longest[1]=1;
//     for(int i=2;i<=n_max;i++)
//     {   collatz[i]=countCollatz(i,n_max,collatz);
//         if(collatz[i]>=collatz[longest[i-1]])   longest[i]=i;
//         else                                    longest[i]=longest[i-1]; 
//     }
// 
//     int t; scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n; scanf("%d",&n);
//         printf("%d\n",longest[n]);
//     }
    
//     return 0;
// }

/**
//Try 3:  1/13 passed. TC #1-12: Segmentation fault. Score: 7.69/100. Same as Try 2. Somehow error changed from wrong answer to segmentation fault.
unsigned long long next(unsigned long long n)
{   if (n%2==0) return (n/2);
    else        return (3*n+1);
}
unsigned long long countCollatz(unsigned long long n, unsigned long long n_max,unsigned long long collatz[])
{   if (n>n_max)        return (1+countCollatz(next(n),n_max,collatz));
    if (collatz[n]==0)  collatz[n]=(1+countCollatz(next(n),n_max,collatz));
    return collatz[n];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n_max=5*10^6;
    unsigned long long collatz[5*10^6+1]={};
    unsigned long long longest[5*10^6+1];
    
    int t; scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        collatz[1]=1;longest[1]=1;
        for(int i=2;i<=n;i++)
        {   collatz[i]=countCollatz(i,n_max,collatz); //printf("%llu ",collatz[i]);
            if(collatz[i]>=collatz[longest[i-1]])   longest[i]=i;
            else                                    longest[i]=longest[i-1]; 
        }
        printf("%llu\n",longest[n]);
    }
    
    return 0;
}
*/

// // Try 4: Modified Try 3: 9/13 passed. TC#9-12 shows TLE. Score: 69.23/100 
// // Idea: In hackerrank, stack space is limited. If we declare arrays in function, stack space is used. Instead declare them globally, so that data segment is used.
// // Also, Try 2 and 3 had a basic issue - 5000000 is not same as 5*10^6 since ^ is bitwise OR operator :D
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// int n_max=5000000;
// unsigned long long collatz[5000001]={};
// unsigned long long longest[5000001];

// unsigned long long next(unsigned long long n)
// {   if (n%2==0) return (n/2);
//     else        return (3*n+1);
// }
// unsigned long long countCollatz(unsigned long long n, unsigned long long n_max,unsigned long long collatz[])
// {   if (n>n_max)        return (1+countCollatz(next(n),n_max,collatz));
//     if (collatz[n]==0)  collatz[n]=(1+countCollatz(next(n),n_max,collatz));
//     return collatz[n];
// }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     int t; scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n; scanf("%d",&n);
//         collatz[1]=1;longest[1]=1;
//         for(int i=2;i<=n;i++)
//         {   if (collatz[i]==0)
//                 collatz[i]=countCollatz(i,n_max,collatz); //printf("%llu ",collatz[i]);
//             if(collatz[i]>=collatz[longest[i-1]])   longest[i]=i;
//             else                                    longest[i]=longest[i-1]; 
//         }
//         printf("%llu\n",longest[n]);
//     }
//     return 0;
// }

//Try 5: 13/13 TC passed. Score:100/100. Modified Try 2 with Try 4 in mind.
int n_max=5000000;
unsigned long long collatz[5000001]={};
unsigned long long longest[5000001];

unsigned long long next(unsigned long long n)
{   if (n%2==0) return (n/2);
    else        return (3*n+1);
}
unsigned long long countCollatz(unsigned long long n)
{   if (n>n_max)        return (1+countCollatz(next(n)));
    if (collatz[n]==0)  collatz[n]=1+countCollatz(next(n));
    return collatz[n];
}
int main() {
    collatz[1]=1;longest[1]=1;
    for(int i=2;i<=n_max;i++)
    {   if (collatz[i]==0)
            collatz[i]=countCollatz(i); 
        if(collatz[i]>=collatz[longest[i-1]])   longest[i]=i;
        else                                    longest[i]=longest[i-1]; 
    }
    
    int t; scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        printf("%llu\n",longest[n]);
    }
    
    return 0;
}



