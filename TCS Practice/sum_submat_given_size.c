/*Find Maximum Sum Submatrix in a given matrix
Given a M x N matrix, calculate maximum sum submatrix of size k x k in a given M x N matrix in O(M*N) time. Here, 0 < k < M, N.

For example, consider below 5 x 5 matrix

[  3 -4  6 -5  1 ]
[  1 -2  8 -4 -2 ]
[  3 -8  9  3  1 ]
[ -7  3  4  2  7 ]
[ -3  7 -5  7 -6 ]

If k = 2, maximum sum k x k sub-matrix is

[ 9 3 ]
[ 4 2 ]

If k = 3, maximum sum k x k sub-matrix is

[ 8 -4 -2 ]
[ 9  3  1 ]
[ 4  2  7 ]*/

#include <stdio.h>
#include <limits.h>
int main()
{   int n,k,i,j,sum,a[50][50],stripsum[50][50],subsum[50][50],maxsum=INT_MIN,posi=-1,posj=-1;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(j=0;j<n;j++)
    {   sum=0;
        for(i=0;i<k;i++)
            sum+=a[i][j];
        stripsum[0][j]=sum;
        for(i=1;i<n-k+1;i++)
        {   sum+=a[i+k-1][j]-a[i-1][j];
            stripsum[i][j]=sum;
        }
    }
    for(i=0;i<n-k+1;i++)
    {   sum=0;
        for(j=0;j<k;j++)
            sum+=stripsum[i][j];
        subsum[i][0]=sum;
        if(sum>maxsum)
        {   maxsum=sum;
            posi=i;
            posj=j;
        }
        for(j=1;j<n-k+1;j++)
        {   sum+=stripsum[i][j+k-1]-stripsum[i][j-1];
            subsum[i][j]=sum;
            if(sum>maxsum)
            {   maxsum=sum;
                posi=i;
                posj=j;
            }
        }
    }
    printf("Maxsum=%d\n",maxsum);
    for(i=posi;i<posi+k;i++)
    {   for(j=posj;j<posj+k;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0;i<n-k+1;i++)
    {   for(j=0;j<n-k+1;j++)
            printf("%d ",subsum[i][j]);
        printf("\n");
    }
    return 0;
}
/*5 3
1 1 1 1 1
2 2 2 2 2
3 8 6 7 3
4 4 4 4 4
5 5 5 5 5
Maxsum=48
8 6 7
4 4 4
5 5 5

Process returned 0 (0x0)   execution time : 28.366 s
Press any key to continue.
*/

/*
5 3
3 -4 6 -5 1
1 -2 8 -4 -2
3 -8 9 3 1
-7 3 4 2 7
-3 7 -5 7 -6
Maxsum=28
8 -4 -2
9 3 1
4 2 7

Process returned 0 (0x0)   execution time : 59.265 s
Press any key to continue.

*/

/*
5 2
3 -4 6 -5 1
1 -2 8 -4 -2
3 -8 9 3 1
-7 3 4 2 7
-3 7 -5 7 -6
Maxsum=18
9 3
4 2

-2 8 5 -10
-6 7 16 -2
-9 8 18 13
0 9 8 10

Process returned 0 (0x0)   execution time : 2.795 s
Press any key to continue.
*/
