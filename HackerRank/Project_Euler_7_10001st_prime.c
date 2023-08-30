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
int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        int num=2;
        int count=0;
        while(count<n) 
        {   int prime=1;
            for(int i=2;i<=sqrt(num);i++)
                if(num%i==0)    {prime=0;break;}
            if (prime==1)   count++;
            if(count==n)    printf("%d\n",num);
            num++;      
        }
    }
    return 0;
}
