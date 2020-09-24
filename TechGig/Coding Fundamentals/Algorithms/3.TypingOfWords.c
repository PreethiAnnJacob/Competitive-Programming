/*
Typing Of Words (100 Marks)
ZS the Coder is coding on a crazy computer. If you don't type in a word for a c consecutive seconds, everything you typed disappear!
More formally, if you typed a word at second a and then the next word at second b, then if b - a c, just the new word is appended to other words on the screen. If b - a > c, then everything on the screen disappears and after that the word you have typed appears on the screen.
For example, if c = 5 and you typed words at seconds 1, 3, 8, 14, 19, 20 then at the second 8 there will be 3 words on the screen. After that, everything disappears at the second 13 because nothing was typed. At the seconds 14 and 19 another two words are typed, and finally, at the second 20, one more word is typed, and a total of 3 words remain on the screen.
You're given the times when ZS the Coder typed the words. Determine how many words remain on the screen after he finished typing everything.


Input Format
You will be given two integers where n & c represents the number of words ZS the Coder typed and the crazy computer delay respectively.


Constraints
1 < n < 10^5
1 < c < 10^9


Output Format
Print a single positive integer, the number of words that remain on the screen after all n words was typed, in other words, at the second tn.


Sample TestCase 1
Input
5 
6
1 
3 
8 
14 
19 
20
Output
3
*/

#include<stdio.h>
int main(int argc, char *a[])
{	int w=0,n,c;
	scanf("%d%d",&c,&n);
	int a1;
	scanf("%d",&a1);
	for(int i=2;i<=n;i++){
		int a2;
		scanf("%d",&a2);
		if((a2-a1)>c)	w=1;
		else	w++;
		a1=a2;
	}
	printf("%d",w);
}
