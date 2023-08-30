/*Project Euler #8: Largest product in a series - EASY
Find the greatest product of K consecutive digits in the N digit number.

Input Format

First line contains T that denotes the number of test cases.
First line of each test case will contain two integers N & K.
Second line of each test case will contain a N digit integer.

Constraints
1<=T<=100
1<=K<=7
K<==N<=1000

Output Format

Print the required answer for each test case.

Sample Input 0

2
10 5
3675356291
10 5
2709360626
Sample Output 0

3150
0
Explanation 0

For 3675356291 and selecting k=5 consequetive digits, we have 36753, 67535, 75356, 53562, 35629 and 56291. Where 6x7x5x3x5 gives maximum product as 3150
For 2709360626, 0 lies in all selection of 5 consequetive digits hence maximum product remains 0
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
        int k; 
        scanf("%d %d",&n,&k);
        char* num = (char *)malloc(512000 * sizeof(char));
        scanf("%s",num);

        //Try1 : 1/10 testcase passed. Testcase#0 only passed. Rest show Runtime error.
        // int maxproduct=1;
        // for(int i=0;i<k;i++)
        //     maxproduct*=(num[i]-'0');
        // for(int i=k,product=maxproduct;i<=n-k;i++)
        // {   product = product/(num[i-k]-'0')*(num[i]-'0');
        //     if (product>maxproduct) maxproduct=product;
        // }
        // printf("%d\n",maxproduct);

        //Try 2: Same 1/10 passed. Error with n=5 k=3 num=10234 was also fixed. But same Testcase #1-#9 failed- Shows Wrong Answer.
        // long maxproduct=1;
        // for(int i=0;i<k;i++)
        // {   if (num[i]=='0')    {maxproduct=0;break;}
        //     maxproduct*=(num[i]-'0');
        // }
        // long product=maxproduct;
        // for(int i=k;i<n;i++)
        // {   if (product!=0) 
        //     {   if (num[i]=='0')    {product=0;break;}
        //         product = product/(num[i-k]-'0')*(num[i]-'0');     
        //     }
        //     else 
        //     {   product=1;
        //         for(int j=i-k+1;j<=i;j++)
        //         {   if (num[j]=='0')    {product=0;break;}
        //             product*=(num[j]-'0');
        //         }
        //     }
        //     if (product>maxproduct) maxproduct=product;
        // }
        // printf("%ld\n",maxproduct);
        
        // Try 3: TLE for all 10 testcases
        // int maxproduct=1; 
        // for(int i=0;i<=n-k;i++)
        // {   int product=1;
        //     for(int j=i;j<=i+k-1;i++)
        //     {   product=product*(num[j]-'0');
        //     }
        //     if (product>maxproduct) maxproduct=product;
        // }
        // printf("%d\n",maxproduct);

        //Try 4: 10/10 working. But O(n^2)
        int maxproduct=-1; 
        for(int i=0;i<=n-k;i++)
        {   int product=1;
            for(int j=i;j<=i+k-1;j++)
            {   product=product*(num[j]-'0');
            }
            if (product>maxproduct) maxproduct=product;
        }
        printf("%d\n",maxproduct);
        
    }
    return 0;
}



