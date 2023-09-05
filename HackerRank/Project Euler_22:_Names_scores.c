/*Project Euler #22: Names scores
You are given around five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list in sample is sorted into alphabetical order, PAMELA, which is worth 16+1+13+5+12+1=48, is the 5th name in the list. So, PAMELA would obtain a score of 5*48=240.

You are given Q queries, each query is a name, you have to print the score.

Input Format

The first line contains an integer N, i.e., number of names.
Next N lines will contain a Name.
Followed by integer Q followed by Q lines each having a word.

Constraints
1<=N<=5200
Length of each word will be less than 12
1<=Q<=100

Output Format

Print the values corresponding to each test case.

Sample Input

5
ALEX
LUIS
JAMES
BRIAN
PAMELA
1
PAMELA
Sample Output

240
Explanation

Explained in statement.
*/


// Try 1: 2/2 testcases passed.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int nameWhere(char query[],char names[][12],int nameSize)
{   for (int i=0;i<nameSize;i++)
        if (strcmp(query,names[i])==0)
            return (i+1);
    return -1;
}
int charScore(char ch)
{   if (ch>='A' && ch <='Z')
        return (ch-'A'+1);
    if (ch>='a' && ch <='z')
        return (ch-'a'+1);
    return ch;
}
int stringScore(char str[])
{   int i=0; int score=0;
    while(str[i]!='\0')
    {   score+=charScore(str[i]);
        i++;
    }
    return score;
}
int main() {
    char names[5200][12]={};
    int n,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",names[i]);
    for(int i=0;i<=n-2;i++)
    {   int pos=i;
        for(int j=i+1;j<=n-1;j++)
            if ( strcmp(names[j],names[pos]) < 0 )
                pos=j;
        char temp[12];strcpy(temp,names[i]);
        strcpy(names[i],names[pos]);
        strcpy(names[pos],temp);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {   char query[12];scanf("%s",query);
        printf("%d\n",( nameWhere(query, names, n) * stringScore(query) ));
    }
    return 0;
}
