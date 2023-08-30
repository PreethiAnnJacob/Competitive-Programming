/*Project Euler #9: Special Pythagorean triplet
A Pythagorean triplet is a set of three natural numbers, a<b<c, for which, a^2+b^2=c^2
For example, 3^2+4^2=9+16=25=5^2

Given N, Check if there exists any Pythagorean triplet for which a+b+c =N
Find maximum possible value of abc among all such Pythagorean triplets, If there is no such Pythagorean triplet print -1.

Input Format

The first line contains an integer T i.e. number of test cases.
The next T lines will contain an integer N.

Constraints
1<=T<=3000
1<=N<=3000

Output Format
Print the value corresponding to each test case in separate lines.

Sample Input 0

2
12
4
Sample Output 0

60
-1
Explanation 0

For N=12, we have a triplet {3,4,5}, whose product is 60.
For N=4, we don't have any pythagorean triple.
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);

        //Try 1: 5/8 TC passed. TC#5,6,7 failed due to TLE.
        // int maxabc=-1;
        // for(int c=n-3;c>=3;c--)
        // {   for(int b=n-c-1;b>=2;b--)
        //     {   if (c>b)
        //         {   int a=n-(b+c);
        //             if(b>a &&  (a*a+b*b==c*c) && (a*b*c>maxabc))    maxabc=a*b*c;
        //         }
        //     }
        // }
        // printf("%d\n",maxabc);

        //Try 2:8/8 testcases passed. 
        int maxabc=-1;
        if (n%2==0)
        {   for (int a=1;a<=n/3;a++)
            {   if ( (n*(n-2*a)) % (2*(n-a)) == 0 )
                {   int b=(n*(n-2*a)) / (2*(n-a));
                    int c=n-a-b;
                    if (a*b*c>maxabc)   maxabc=a*b*c;
                }
            }
        }
        printf("%d\n",maxabc);
        /*
        Note 1: 
        If a<b<c in the Pythogorian triples, max a is said to be n//3 and max b is said to be n//2. Don't know the logic behind it
        
        Note 2: 
        n is always Even if there is Pythogorian triplets whose sum is n.
        We know a^2+b^2=c^2 and    a+b+c    =n
                O    O    E and    O O E     E
                O    E    O and    O E O     E
                E    E    E and    E E E     E
        
        Note 3:
        Formula for b from n and a:
        We know a^2+b^2=c^2 and a+b+c=n
        n^2 = (a+b+c)^2 = a^2+b^2+c^2+2(ab+bc+ca) = c^2+c^2+2(ab+bc+ca) = 2c^2+2(ab+bc+ca) = 2(c^2+ab+bc+ca) = 2(c^2+(ab+ca)+bc) = 2(c^2+a(b+c)+bc) = 2(c^2+a(n-a)+bc) = 2(c^2+na-a^2+bc) 
            = 2(c^2-a^2+na+bc) = 2(b^2+na+bc) = 2(b^2+bc)+2na = 2b(b+c)+2na
        So n^2 = 2b(b+c)+2na
        So b = (n^2 - 2na) / (2(b+c)) = (n(n-2a)) / (2(b+c)) = (n(n-2a)) / (2(n-a)).
        */

        
    }
    return 0;
}
