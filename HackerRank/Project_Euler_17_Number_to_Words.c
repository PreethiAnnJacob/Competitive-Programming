/*Project Euler #17: Number to Words

The numbers 1 to 5 written out in words are One, Two, Three, Four, Five
First character of each word will be capital letter for example: 104382426112 is One Hundred Four Billion Three Hundred Eighty Two Million Four Hundred Twenty Six Thousand One Hundred Twelve
Given a number, you have to write it in words.

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=10
0<=N<=10^12

Output Format
Print the values corresponding to each test case.

Sample Input
2
10
17

Sample Output
Ten
Seventeen

Explanation
Follow the rules given in statement.
*/

//Try 1: 6/6. Score: 100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char onetoNine[10][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char elevenToNinteeen[10][10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
char multiplesOfTen[10][10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
char special[5][10]={"Hundred","Thousand","Million","Billion","Trillion"};

char* numToString(long n)
{   int nd= (n==0) ? 1 : (log10(n)+1);    
    long pos=pow(10,nd-1); //printf("%ld:%d:%ld",n,nd,pos);
    char *temp=malloc(300*sizeof(char));
    if (n>999)
    {   int specialPos = (int)ceil(nd/3.0) - 1;
        long threeGroupPos = pow(1000,specialPos);
        strcpy(temp,numToString(n/threeGroupPos));
        strcat(temp," ");
        strcat(temp,special[specialPos]);
        strcat(temp," ");
        strcat(temp,numToString(n%threeGroupPos));
    }
    else if(n>99)
    {   int specialPos = (int)ceil(nd/3.0) - 1;
        strcpy(temp,numToString(n/pos));
        strcat(temp," ");
        strcat(temp,special[specialPos]);  
        if(n%pos!=0) 
        {   strcat(temp," ");
            strcat(temp,numToString(n%pos));
        }  
    }
    else if (n>9)
    {   if(n>=11 && n<=19)    strcat(temp,elevenToNinteeen[n%pos]);
        else                
        {   strcat(temp,multiplesOfTen[n/pos]);
            if(n%pos!=0) 
            {   strcat(temp," ");
                strcat(temp,numToString(n%pos));
            }
        }
    }
    else    strcat(temp,onetoNine[n]);  
    return temp;
}
int main() {
    int t;  scanf("%d",&t);
    for (int i=0;i<t;i++)
    {   long n;  scanf("%ld",&n);
        char str[300]={};
        strcat(str,numToString(n));
        printf("%s\n",str);
    }
    return 0;
}

/*
//Try 2: 6/6. Score: 100. Same as Try 1. Compacted version

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char onetoNine[10][10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
char elevenToNinteeen[10][10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen"};
char multiplesOfTen[10][10]={"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
char special[5][10]={"Hundred","Thousand","Million","Billion","Trillion"};

char* numToString(long n)
{   int nd= (n==0) ? 1 : (log10(n)+1);          //No Of Digits in n 
    long placePos = pow(10,nd-1);               //e.g. placePos=1000 for 1234, 100 for 123
    int specialPos = (int)ceil(nd/3.0) - 1;     //Index position for special{}
    long threeGroupPos = pow(1000,specialPos);  //To consider three number groups, i.e. 123,456789 = (123)Million (456)thousand (789)
    long pos = (n>999) ? threeGroupPos : placePos;
    char *temp=malloc(300*sizeof(char));
    if (n>99)
    {   strcpy(temp,numToString(n/pos));
        strcat(temp," ");
        strcat(temp,special[specialPos]);
    }
    else if (n>9)
    {   if(n>=11 && n<=19)      strcat(temp,elevenToNinteeen[n%placePos]);
        else                    strcat(temp,multiplesOfTen[n/placePos]);
    }
    else    strcat(temp,onetoNine[n]);  
    if(n>20 && n%pos!=0) 
    {   strcat(temp," ");
        strcat(temp,numToString(n%pos));
    }
    return temp;
}
int main() {
    int t;  scanf("%d",&t);
    for (int i=0;i<t;i++)
    {   long n;  scanf("%ld",&n);
        char str[300]={};
        strcat(str,numToString(n));
        printf("%s\n",str);
    }
    return 0;
}
*/
