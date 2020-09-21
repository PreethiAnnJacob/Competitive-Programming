/*
Pattern Problem - 43 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
            0
         1 0 1
      2 1 0 1 2
   3 2 1 0 1 2 3
4 3 2 1 0 1 2 3 4 

Input Format
You will take an integer input n from stdin.

Constraints
0 <= n <= 1000

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i);j++)
			printf("  ");
		for(int j=1,count=1,k=i-1;j<=(2*i-1);j++,count++){
			if( i==1 )
				printf("%d \n",k);
			else if(j!=(2*i-1))
				printf("%d ",k);
			else
				printf("%d\n",k);
			if (count<i)	k--;
			else			k++;
		}
	}
}
