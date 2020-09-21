/*
Pattern Problem - 40 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
            1
         3 2 1
      5 4 3 2 1
   7 6 5 4 3 2 1
9 8 7 6 5 4 3 2 1 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

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
		for(int j=(2*i-1);j>=1;j--){
			if(j==1)
				printf("%d\n",j);
			else
				printf("%d ",j);	
		}
	}
}
