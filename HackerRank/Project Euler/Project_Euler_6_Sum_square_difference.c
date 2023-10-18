/*Project Euler #6: Sum square difference
The sum of the squares of the first ten natural numbers is, 1^2+ 2^2+...+10^2 = 385. The square of the sum of the first ten natural numbers is,(1+2+...+10)^2=55^2=3025 . Hence the absolute difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025-385=2640.

Find the absolute difference between the sum of the squares of the first  natural numbers and the square of the sum.

Input Format

First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1<=T<=10^4
1<=N<=10^4

Output Format

Print the required answer for each test case.

Sample Input 0

2
3
10
Sample Output 0

22
2640
Explanation 0

For  N=3,(1+2+3)^2-(1^2+2^2+3^2)=22 
For N=10,(1+2+...+10)^2 - (1^2+...+10^2)=2640 

*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//Try1: 2/2 testcases passed
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        long s1=0;long s2=0;
        for(int i=1;i<=n;i++)
        {   s1+=i;
            s2+=i*i;
        }
        printf ("%ld\n",(s1*s1-s2));
    }
    return 0;
}
