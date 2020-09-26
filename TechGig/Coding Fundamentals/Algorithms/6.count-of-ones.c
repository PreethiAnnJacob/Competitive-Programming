/*
Count Of 1's (100 Marks)
Given a binary array sorted in non-increasing order, count the number of 1's in it.

Input Format
You will be given an integer array of size N.

Constraints
1 < N < 10^5
0< = A[i]< = 1


Output Format
You need to print the count of 1's.

Sample TestCase 1
Input
7
1
1
0
0
0
0
0
Output
2
*/

/* Read input from STDIN. Print your output to STDOUT*/
#include<stdio.h>
int main(int argc, char *a[])
{	int n,val,count=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&val);
		count+=val;
	}
	printf("%d",count);
}
