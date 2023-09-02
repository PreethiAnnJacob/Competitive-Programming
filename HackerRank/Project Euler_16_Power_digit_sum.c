/*Project Euler #16: Power digit sum
2^9=512 and the sum of its digits is 5+1+2=8.
What is the sum of the digits of the number 2^N?

Input Format
The first line contains an integer T, i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=100
1<=N<=10^4

Output Format
Print the values corresponding to each test case.

Sample Input
3
3
4
7

Sample Output
8
7
11

Explanation
2^3=8, sum of digits is 8.
2^4=16, sum of digits is 7.
2^7=128, sum of digits is 11.
*/

/*
#Try 1 in Python. 10/10. Score:100
# Enter your code here. Read input from STDIN. Print output to STDOUT
for i in range(int(input())):
    n=int(input())
    num=2**n
    sd=0
    while(num>0):
        sd+=num%10
        num=num//10
    print(sd,end="\n")
*/

/*//Try 2 in C. 1/10. TC#1-9:Wrong answer. Score:0
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;scanf("%d",&t);
    for (int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        int num=(int)pow(2,n);
        int sd=0;
        while(num>0)
        {   sd+=num%10;
            num=num/10;
        }
        printf("%d\n",sd);  
    }
    return 0;
}
*/

/*
//Try 3: 4/10 passed. TC #4-#9 due to TLE. Score: 33.33/100
//Idea: Convert to string and do multiplication step by step
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void twice(char str[])
{   int sd=0;
    int c=0;int i;
    for(i=0;i<strlen(str);i++)
    {   int d=str[i]-'0';   d=d*2;
        if (c==1)           d++;
        if (d>9)    {c=1;d=d%10;} 
        else        c=0;
        str[i]=d+'0';
    }
    if (c==1)   str[i++]='1';
    str[i]='\0';
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;scanf("%d",&t);
    for (int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        char str[4000]="1";
        for(int i=1;i<=n;i++)
            twice(str);
        int sd=0;
        for(int i=0;i<strlen(str);i++)
            sd+=str[i]-'0';
        printf("%d\n",sd);
    }
    return 0;
}
*/

//Try 4: 10/10. Score:100. Idea: Save intermediate values dynamically to array
// Note: str size kept as 4000 since 2^(10^4) has 3011 digits(Calculation: log(2^(10^4)))+1 = (10^4)log 2 +1 = (10^4)(0.301029996)+1 = 3011 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sod[10001]={};//size=index0 + index1 till 10000
int twice(char str[])
{   int sd=0;   int c=0;    int i;
    for(i=0;i<strlen(str);i++)
    {   int d=str[i]-'0';   d=d*2+c;
        if (d>9)    {c=1;d=d%10;} 
        else        c=0;
        str[i]=d+'0';
        sd=sd+d;
    }
    if (c==1)   {str[i++]='1';sd++;}
    str[i]='\0';
    return sd;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char str[4000]="2";  
    sod[0]=1;    sod[1]=2;
    for(int i=2;i<=10000;i++)
        sod[i] = twice(str);
    
    int t;scanf("%d",&t);
    for (int a0=0;a0<t;a0++)
    {   int n; scanf("%d",&n);
        printf("%d\n",sod[n]);
    }
    return 0;
}



