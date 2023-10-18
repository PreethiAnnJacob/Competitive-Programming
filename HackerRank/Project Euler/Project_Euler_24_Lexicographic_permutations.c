/*Project Euler #24: Lexicographic permutations - Easy
A permutation is an ordered arrangement of objects. For example, dabc is one possible permutation of the word abcd. If all of the permutations are listed alphabetically, we call it lexicographic order. The lexicographic permutations of abc are: abc,acb,bac,bca,cab,cba
What is the Nth lexicographic permutation of the word abcdefghijklm?

Input Format

The first line contains an integer  , i.e., number of test cases.
Next  lines will contain an integer .

Constraints
1<=T<=1000
1<=N<=13!

Output Format

Print the values corresponding to each test case.

Sample Input

2
1
2
Sample Output

abcdefghijklm
abcdefghijkml
*/

//Try 1 in C: TC:10/10 Score:100/100
// Logic from https://stemhash.com/efficient-permutations-in-lexicographic-order/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long factorial(int n)
{   long p=1;
    for(int i=1;i<=n;i++)
        p=p*i;
    return p;
}
int main() {
    int t; long num;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   char str[15]="abcdefghijklm";   int n=13;
        scanf("%ld",&num);
        num=num-1;
        char perm[15]="";
        while(n>0)
        {   long rem=num%factorial(n-1);
            long quo=num/factorial(n-1);
            strncat(perm,&str[quo],1);
            
            char temp[15]="";
            strncpy(temp,str,quo);
            strcat(temp,&str[quo+1]);
            strcpy(str,temp);
            
            num=rem;    n=n-1;  
        }
        printf("%s\n",perm);
    }
    return 0;
}
