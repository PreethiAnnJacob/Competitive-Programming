/*
Maximum size square sub-matrix with all 1s
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
*/
#include <stdio.h>
long long int min(long long int a,long long int b)
{   if(a<b)
        return a;
    else
        return b;
}
int main()
{   long long int p,q,i,j,m[50][50],s[50][50],ans=0,posi=-1,posj=-1;
    scanf("%lld%lld",&p,&q);
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%lld",&m[i][j]);

    for(j=0;j<q;j++)
        s[0][j]=m[0][j];
    for(i=0;i<p;i++)
        s[i][0]=m[i][0];
    for(i=1;i<p;i++)
    {   for(j=1;j<q;j++)
        {   if(m[i][j]==1)
                s[i][j]=min(min(s[i-1][j-1],s[i-1][j]) , s[i][j-1]) +1;
            else
                s[i][j]=0;
            if(ans<s[i][j])
            {   ans=s[i][j];
                posi=i;
                posj=j;
            }
        }
    }
    printf("%lld %lld %lld\n",ans,posi,posj);
    return 0;
}
/*
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0
3 4 3

Process returned 0 (0x0)   execution time : 6.427 s
Press any key to continue.
*/
