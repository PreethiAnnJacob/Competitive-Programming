/*
Pattern Problem - 9 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
E D C B A
E D C B A
E D C B A
E D C B A
E D C B A

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=4;j>=0;j--){
			if(j==0)
				printf("%c\n",(ch+j));
			else
				printf("%c ",(ch+j));
		}
	}
}
