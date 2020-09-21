/*
Pattern Problem - 5 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
A B C D E
A B C D E
A B C D E
A B C D E
A B C D E 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 1000

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=4;j++){
			if(j==4)
				printf("%c\n",(ch+j));
			else
				printf("%c ",(ch+j));
		}
	}
}
