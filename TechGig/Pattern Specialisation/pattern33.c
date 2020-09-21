/*
Problem Statement
Discussions
My Submissions
Pattern Problem - 33 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-

A B C D E
   A B C D
      A B C
         A B
            A 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i;j++)
			printf("  ");
		for(int j=1;j<=i;j++)
			if(j==i)
				printf("%c\n",(ch+j-1));
			else
				printf("%c ",(ch+j-1));
	}
}
