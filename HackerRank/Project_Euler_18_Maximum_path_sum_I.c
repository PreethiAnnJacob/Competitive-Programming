/* Project Euler #18: Maximum path sum I
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23. The path is denoted by numbers in bold.
        (3)
      (7)  4
    2   (4)    6
  8    5    (9)   3
That is, 3+7+4+9=23.

Find the maximum total from top to bottom of the triangle given in input.

Input Format

First line contains T, the number of testcases. For each testcase:
First line contains N, the number of rows in the triangle.
For next N lines, i'th line contains i numbers.

Constraints
1<=T<=10
1<=N<=15
numbers E [0,100)

Output Format
For each testcase, print the required answer in a newline.

Sample Input
1
4
3
7 4
2 4 6
8 5 9 3

Sample Output

23
Explanation

As shown in statement.
*/

//Try 1: 6/6
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long maxPathSum(int num[15][15],int n,int r,int c)
{   if(r<c || r<0  || r>=n || c<0 || c>=n)      return 0;
    if (r==n-1)                                 return num[r][c]; 
    long adj1 = maxPathSum(num, n, r+1, c);
    long adj2 = maxPathSum(num, n, r+1, c+1);
    long maxAdjPathSum = (adj1>=adj2) ? adj1 : adj2; 
    return num[r][c]+maxAdjPathSum;
}
int main() {
    int t;  scanf("%d",&t);
    for (int a0=0;a0<t;a0++)
    {   int n;  scanf("%d",&n);
        int num[15][15];
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                scanf("%d",&num[i][j]);
        printf("%ld\n",maxPathSum(num, n, 0, 0));
    }  
    return 0;
}
