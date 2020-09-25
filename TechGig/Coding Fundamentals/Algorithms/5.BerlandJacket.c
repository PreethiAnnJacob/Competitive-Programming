/*
Berland Jacket (100 Marks)
According to rules of the Berland fashion, a jacket should be fastened by all the buttons except only one, but not necessarily it should be the last one. Also if the jacket has only one button, it should be fastened, so the jacket will not swinging open.
You are given a jacket with n buttons. Determine if it is fastened in a right way.


Input Format
You will be given a function with integer array as a single argument with the number of elements ai. The number ai = 0 if the i-th button is not fastened. Otherwise ai = 1.


Constraints
1 <= n <= 10^3
0 < = ai < = 1

Output Format
Return the word "YES" if the jacket is fastened in a right way. Otherwise return the word "NO".


Sample TestCase 1
Input
3
1 
0 
1
Output
YES
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int n,val;
	scanf("%d",&n);
	if(n==1){
		scanf("%d",&val);
		ifa(val==0)	printf("NO");
		else 			printf("YES");
	}
	else{
		int i,unfastened;
		for(i=1,unfastened=0;i<=n;i++){
			scanf("%d",&val);
			if(val==0){
				if(unfastened==1){
					printf("NO");
					break;
				}
				else
					unfastened++;
			}
		}
		if(i==n+1)	printf("YES");	
	}
}
