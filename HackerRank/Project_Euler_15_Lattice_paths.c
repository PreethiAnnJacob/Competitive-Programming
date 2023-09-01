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

//Try 1 in Python: 11/11. Score:100
//Trying in C:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 2in C: 1/11. TC #1-10 failed due to runtime error
unsigned long long factorial(int n)
{   return (unsigned long long )(round(tgamma(n+1)));
}
int main() {
    int t,m,n;
    int limit=1000000007;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {   scanf("%d%d",&m,&n);
        int ways = (factorial(m+n)/factorial(m)/factorial(n))%limit; 
        printf("%d\n",ways);
    }    
    return 0;
}
