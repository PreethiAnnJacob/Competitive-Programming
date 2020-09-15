/*Pangram Checking
Given a string check if it is Pangram or not. A pangram is a sentence containing every letter in the English Alphabet.

Examples : The quick brown fox jumps over the lazy dog ” is a Pangram [Contains all the characters from ‘a’ to ‘z’]
“The quick brown fox jumps over the dog” is not a Pangram [Doesn’t contains all the characters from ‘a’ to ‘z’, as ‘l’, ‘z’, ‘y’ are missing]
*/
#include <string.h>
#include <stdio.h>
int main()
{   char str[100],hash[26];
    int i,index,p=1;
    gets(str);
    for(i=0;i<26;i++)
        hash[i]=0;
    for(i=0;i<strlen(str);i++)
    {   if('A'<=str[i] && str[i]<='Z')
            index=str[i]-'A';
        else if('a'<=str[i] && str[i]<='z')
            index=str[i]-'a';
        hash[index]=1;
    }
    for(i=0;i<26;i++)
    {   if(hash[i]==0)
        {   p=0;
            break;
        }
    }
    if(p==1)
        printf("Pangram\n");
    else
        printf("Not Pangram\n");
    return 0;
}
/*
The quick brown fox jumps over the lazy dog
Pangram

Process returned 0 (0x0)   execution time : 2.629 s
Press any key to continue.
*/
/*
The quick brown fox jumps over the dog
Not Pangram

Process returned 0 (0x0)   execution time : 5.655 s
Press any key to continue.

*/
