/*
zscoder and string (100 Marks)
ZScoder loves simple strings! A string t is called simple if every pair of adjacent characters are distinct. For example ab, aba, zscoder are simple whereas aa, add are not simple.

zscoder is given a string s. He wants to change a minimum number of characters so that the string s becomes simple. Help him with this task!


Input Format
You will be given a function which contains the string s, the string given to zscoder as a single argument. The string s consists of only lowercase English letters.


Constraints
1 < = |s| < = 2*105

Output Format
Return the simple string s' the string s after the minimal number of changes. If there are multiple solutions, you may output any of them.Note that the string s' should also consist of only lowercase English letters.


Sample TestCase 1
Input
aab
Output
bab
*/

#include<stdio.h>
#include<string.h>
int main(int argc, char *a[])
{	char s[1000];
	scanf("%s",s);
	for(int i=0;i<=strlen(s)-2;i++){
		if(i<=strlen(s)-3){	
			if(s[i]==s[i+1] & s[i]==s[i+2]){
				s[i+1]=s[i]+1;
			}
		}
		if(s[i]==s[i+1]){
			if(i>0){
				if(s[i-1]==s[i]+1)	
					s[i]=s[i]+2;
				else
					s[i]=s[i]+1;
			}
			else
				s[i]=s[i+1]+1;
		}
	}
	printf("%s",s);
}
