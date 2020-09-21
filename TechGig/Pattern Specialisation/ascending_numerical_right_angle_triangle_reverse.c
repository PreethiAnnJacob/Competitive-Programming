/*
Pattern Problem - 17 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{	int n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(j==i)
				printf("%d\n",j);
			else
				printf("%d ",j);
		}
	}
}
