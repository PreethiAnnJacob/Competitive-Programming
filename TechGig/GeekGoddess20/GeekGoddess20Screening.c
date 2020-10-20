/*Coding Challenge - Open Round - Screening
Pokemon Cards (100 Marks)
Misty is fond of pokemons and likes to collect pokemon cards. She has P pokemon cards with her at present. She wants to have a particular number of cards on the Dth day. Her friend Ash is ready to help her to achieve the number. Ash will provide her N cards daily so that a day before the Dth day, she will have the required number of Pokemon cards.

Example:

Misty has cards with her, P = 5

D = 6

Ash will provide her with cards daily, N = 4


Ash provides pokemon cards:

Day 1 = 4

Day 2 = 4

Day 3 = 4

Day 4 = 4

Day 5 = 4


Total cards Ash provides = 4 + 4 + 4 + 4 + 4 = 20

Total number of pokemon cards Misty has on the Dth day = 5 + 20 = 25


Misty is busy with her tournament and wants to know the total number of pokemon cards she will have on Dth day. Can you tell her?




Input Format
The first line of input consists of the number of test cases, T

The only line of each test case consists of three space-separated integers, P, N and D.



Constraints
1<= T <=100

1<= D <=100000

0 <= P, N <=100000



Output Format
For each test case, print the required answer in a separate line.

Sample TestCase 1
Input
2
5 4 6
2 2 2
Output
25
4
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int t,p,n,d;int ans[100];
	scanf("%d",&t);
	for (int i=0;i<t;i++){
		scanf("%d%d%d",&p,&n,&d);
		ans[i]=p+(d-1)*n;
	}
	for (int i=0;i<t;i++){
		printf("%d",ans[i]);
		if(i!=t-1)
			printf("\n");
	}
}
