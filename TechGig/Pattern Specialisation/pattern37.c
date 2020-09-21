/*
Pattern Problem - 37 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-
          A
       B B B
    C C C C C
 D D D D D D D
E E E E E E E E E

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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i);j++)
			printf("  ");
		for(int j=1;j<=(2*i-1);j++){
			if(j==(2*i-1))
				printf("%c\n",ch+i-1);
			else
				printf("%c ",ch+i-1);	
		}
	}
}

