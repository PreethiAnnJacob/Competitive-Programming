/*
Owl Sonya (100 Marks)
Today an outstanding event is going to happen in the forest hedgehog Filya will come to his old fried Sonya!

Sonya is an owl and she sleeps during the day and stay awake from minute l1 to minute r1 inclusive. Also, during the minute k she prinks and is unavailable for Filya.Filya works a lot and he plans to visit Sonya from minute l2 to minute r2 inclusive.
Calculate the number of minutes they will be able to spend together.


Input Format
You will be given a function with five integers l1, r1, l2, r2 and k, providing the segments of time for Sonya and Filya and the moment of time when Sonya prinks as arguments.

Constraints
1 < = l1, r1, l2, r2, k <10^9


Output Format
Return one integer the number of minutes Sonya and Filya will be able to spend together.



Sample TestCase 1
Input
1 
10 
9 
20 
1
Output
2
Explanation
They will be together during minutes 9 and 10.
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int l1,r1,l2,r2,k,spend=0;
	scanf("%d%d%d%d%d",&l1,&r1,&l2,&r2,&k);
	if(l2<=l1 & l1<=r1 & r1<=r2){
		spend=r1-l1+1;
		if(l1<=k & k<=r1)	spend--;
	}
	else if(l1<=l2 & l2<=r2 & r2<=r1){
		spend=r2-l2+1;
		if(l2<=k & k<=r2)	spend--;
	}
	else if(l1<=l2 & l2<=r1 & r1<=r2){
		spend=r1-l2+1;
		if(l2<=k & k<=r1)	spend--;
	}
	else if(l2<=l1 & l1<=r2 & r2<=r1){
		spend=r2-l1+1;
		if(l1<=k & k<=r2)	spend--;
	}
	printf("%d",spend);
}

