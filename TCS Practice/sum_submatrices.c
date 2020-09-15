/*
Given an n x n square matrix, find sum of all sub-squares of size k x k

Given an n x n square matrix, find sum of all sub-squares of size k x k where k is smaller than or equal to n.

Examples :

Input:
n = 5, k = 3
arr[][] = { {1, 1, 1, 1, 1},
{2, 2, 2, 2, 2},
{3, 3, 3, 3, 3},
{4, 4, 4, 4, 4},
{5, 5, 5, 5, 5},
};
Output:
18 18 18
27 27 27
36 36 36


Input:
n = 3, k = 2
arr[][] = { {1, 2, 3},
{4, 5, 6},
{7, 8, 9},
};
Output:
12 16
24 28*/
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

/*
5 3
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
Maxsum=36
3 3 0
4 4 0
5 5 0

18 18 18
27 27 27
36 36 36

Process returned 0 (0x0)   execution time : 22.575 s
Press any key to continue.
*/

/*
3 2
1 2 3
4 5 6
7 8 9
Maxsum=28
5 6
8 9

12 16
24 28

Process returned 0 (0x0)   execution time : 29.012 s
Press any key to continue.
*/
