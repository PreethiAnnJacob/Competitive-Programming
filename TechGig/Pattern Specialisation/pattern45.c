/*
Pattern Problem - 45 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
         1
      1 2 1
   1 2 3 2 1
1 2 3 4 3 2 1 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

Output Format
Your output should be the pattern according to the input which you had entered. 

*/

#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i);j++)
			printf("  ");
		for(int j=1,count=1,k=1;j<=(2*i-1);j++,count++){
			if(j!=(2*i-1))
				printf("%d ",k);
			else
				printf("%d\n",k);
			if (count<i)	k++;
			else			k--;
		}
	}
}
