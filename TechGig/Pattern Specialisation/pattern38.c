/*
Pattern Problem - 38 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 4 then, the pattern should be like this-
         A
      C C C
    E E E E E
G G G G G G G

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 13

Output Format
Your output should be the pattern according to the input which you had entered. 
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int n;char ch='A';
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i);j++)
			printf("  ");
		for(int j=1;j<=(2*i-1);j++){
			if(j==(2*i-1))
				printf("%c\n",ch+2*(i-1));
			else
				printf("%c ",ch+2*(i-1));	
		}
	}
}
