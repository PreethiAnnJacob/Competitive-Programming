/*Project Euler #15: Lattice paths
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

Grid 2x2:
 __ __
|__|__|
|__|__|

Paths possible here from top left to bottom right corner:
__ __     __        __                            
     |      |__       |      |__ __      |__      |
     |         |      |__          |        |__   |__ __
     
How many such routes are there through a NxM grid? As number of ways can be very large, print it modulo (10^9+7).

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain integers N and M.

Constraints
1<=T<=1000
1<=N<=500
1<=M<=500

Output Format
Print the values corresponding to each test case.

Sample Input
2
2 2
3 2

Sample Output
6
10

Explanation
For 2x2 as shown in statement above.
*/

//Try 1 done in Python: 11/11. Score:100
//Trying in C:

// //Try 2 in C: 1/11. TC #1-10 failed due to runtime error. Score:0
// // Extra Note: Noticed SIGFPE, Arithmetic exception with input:500x500. Happened due to overflow corresponding to the datatype. 

// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// unsigned long long factorial(int n)
// {   return (unsigned long long )(round(tgamma(n+1)));
// }
// int main() {
//     int t,m,n;
//     int limit=1000000007;
//     scanf("%d",&t);
//     for(int i=0;i<t;i++)
//     {   scanf("%d%d",&m,&n);
//         int ways = (factorial(m+n)/factorial(m)/factorial(n))%limit; 
//         printf("%d\n",ways);
//     }    
//     return 0;
// }

//Try 3 in C: 11/11 TC passed. Score: 100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Note: Since Intermediate values while multiplication are too big, remember to keep the variables of unsigned long long datatype. e.g. p in modpower(), nr and dr_inv in C(). Otherwise you will keep getting 0 as answer.

//Find x^y mod limit
int modpower(int x,int y,int limit)
{   if (x==1||y==0)   return 1;
    unsigned long long p = modpower(x,y/2,limit);   
    p = (p*p) % limit;                                
    p = (y%2==0) ? p : ((p*x)%limit);
    return p;
}
/*int gcd(int a,int b)
{   if (b>a)    return gcd(b,a);
    if (b==0)   return a;
    return gcd(b,a%b);
}*/
/*  Find inverse(a) mod p
    1.  x is the inverse of a    => ax=1 mod p
    2.  Fermats little theorem  
        => For any integer a and prime number p,                a^p=a mod p    
        => If a is coprime with p(i.e. a is multiple of p),     a^(p-1)=1 mod p
        => So Inverse of a wrt mod p=                           a^(-1)=a^(p-2) mod p 
    3.  Note: 10^9+7 is a prime number. 
    4.  Since we are taking constraints as (n+m)=max 1000, the a considered is always coprime with p(i.e. never a multiple of p). So no need to explicitly check if gcd(a,p)=1              
*/
int modinverse(int a,int limit)
{   /*int gcdvalue = gcd(limit,a);
    if (gcdvalue!=1)    return -1;*/
    int inv = modpower(a,limit-2,limit);
    return inv;
}
//  Find (m+n)Cm mod limit
int C(int m,int n,int limit)
{   int a=(m+n);
    int b= (m<=n) ? m : n;
    unsigned long long nr=1;unsigned long long dr_inv=1;
    for(int i=1;i<=b;i++)
    {   nr=(nr * (a-b+i)) %limit;
        int i_inv = modinverse(i,limit);
        dr_inv = (dr_inv * i_inv) %limit; 
    }
    int c = (nr*dr_inv) %limit;
    return c;
}
int main() {
    int t,m,n;
    int limit=1000000007;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {   scanf("%d%d",&m,&n);
        int ways = C(m,n,limit); 
        printf("%d\n",ways);
    }    
    return 0;
}

