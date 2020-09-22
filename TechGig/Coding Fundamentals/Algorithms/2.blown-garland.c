/*
Blown Garland (100 Marks)
Nothing is eternal in the world, Kostya understood it on the 7-th of January when he saw partially dead four-color garland.

Now he has a goal to replace dead light bulbs, however he doesn't know how many light bulbs for each color are required. It is guaranteed that for each of four colors at least one light is working.
It is known that the garland contains light bulbs of four colors: red, blue, yellow and green. The garland is made as follows: if you take any four consecutive light bulbs then there will not be light bulbs with the same color among them. For example, the garland can look like "RYBGRYBGRY", "YBGRYBGRYBG", "BGRYB", but can not look like "BGRYG", "YBGRYBYGR" or "BGYBGY". Letters denote colors: 'R' red, 'B' blue, 'Y' yellow, 'G' green.
Using the information that for each color at least one light bulb still works count the number of dead light bulbs of each four colors.


Input Format
The first and the only line contains the string s, which describes the garland, the i-th symbol of which describes the color of the i-th light bulb in the order from the beginning of garland:
'R' the light bulb is red,
'B' the light bulb is blue,
'Y' the light bulb is yellow,
'G' the light bulb is green,
'!' the light bulb is dead.


Constraints
4 < = |s| < = 100

Output Format
You need to return the four integers (kr, kb, ky, kg) as strings separated by single space.


Sample TestCase 1
Input
RYBGRYBGR
Output
0 0 0 0
Explanation
There are no dead light bulbs.
*/

#include<stdio.h>
#include<string.h>
char missing(char str[],int i){
	char ch[5]="RBYG";
	for(int index=i-3;index<=i;index++){
		if(index>=0 & index<strlen(str)){
			int nd=0;
			for(int j=0;j<4;j++){
				if((index+j)!=i & str[index+j]=='!'){
					nd++;break;
				}
			}
			if(nd==1)	continue;
			int found[4]={0,0,0,0};
			for(int j=0;j<4;j++){
				int k;
				for(k=0;k<4;k++){
					if(str[index+j]==ch[k]){
						found[k]=1;
						break;
					}
				}
			}
			for(int j=0;j<4;j++)
				if(found[j]==0)
					return ch[j];
		}
	}
	return ' ';
}
int main(int argc, char *a[])
{	char gar[101];int kr=0,kb=0,ky=0,kg=0,nm=0;
	scanf("%s",gar);
	int o=nm;
	do{
		for(int i=0;i<strlen(gar);i++){
			if(gar[i]=='!'){
				char miss=missing(gar,i);
				if(miss!=' ') gar[i]=miss;
				else	nm++;
				if(miss=='R')	kr++;
				else if(miss=='B')	kb++;
				else if(miss=='Y')	ky++;
				else if(miss=='G')	kg++;
			}
		}
		o++;
	}while(o<=nm);
	printf("%d %d %d %d",kr,kb,ky,kg);
}
