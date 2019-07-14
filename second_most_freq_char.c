/*Program to find second most frequent character
Given a string, find the second most frequent character in it. Expected time complexity is O(n) where n is the length of the input string.

Examples:

Input: str = "aabababa";
Output: Second most frequent character is 'b'

Input: str = "abcd";
Output: No Second most frequent character*/
#define NO_OF_CHARS 256
#include <stdio.h>
#include <string.h>
int main()
{   char str[100],c;
    int count[NO_OF_CHARS] = {0}, i,f=0,s=0;
    gets(str);
    for(i=0;i<strlen(str);i++)
        (count[str[i]])++;
    for(i=0;i<256;i++)
    {   if(count[i]>count[f])
        {   s=f;
            f=i;
        }
        else if(count[i]>count[s] && count[i]!=count[f])
            s=i;
    }
    c=s;
    if(c=='\0')
        printf("No second most frequent character\n");
    else
        printf("Second most frequent character  : %c\n",c);
    return 0;
}
/*
aabababa
Second most frequent character  : b

Process returned 0 (0x0)   execution time : 7.788 s
Press any key to continue.
*/

/*
abcd
No second most frequent character

Process returned 0 (0x0)   execution time : 5.859 s
Press any key to continue.

*/

