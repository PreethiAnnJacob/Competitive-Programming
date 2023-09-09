/*Project Euler #26: Reciprocal cycles
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
1/2=0.5
1/3=0.(3)
1/4=0.25
1/5=0.2
1/6=0.1(6)
1/7=0.(142857)
1/8=0.125
1/9=0.(1)
1/10=).1
Where ).1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of smallest d<N for which 1/d contains the longest recurring cycle in its decimal fraction part.

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=1000
4<=N<=10000

Output Format

Print the values corresponding to each test case.

Sample Input

2
5
10
Sample Output

3
7
*/

//Try 1: TC:4/4
//Note: remember about the d<N condition. i.e. if N=7, ans is not 6 but 4
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int map[10001]={};
//map[N] stores the smallest d<=N for which 1/d contains longest recurring cycle in its decimal fraction part. e.g. map[8]=7 since 1/7 has the most number of recurring digits

void fillMap()
{   map[1]=1;// For n=1, 1/1=1 => No decimal points/recurring digits
    int longest=0;
    for(int i=2;i<=10000;i++)
    {   int n=i;
        
        // Since 2 and 5 are factors of the base 10, it doesn't cause the recurring digits. 
        while(n%2==0)   n=n/2;
        while(n%5==0)   n=n/5;
        
        //Idea: Try the long division by hand. Recurring starts when remainder is 1 at any point.
        int digits=0;
        // For n=1, 1/1=1 => No decimal points/recurring digits
        if (n>1)   
        {   int rem=1;
            do
            {   rem=(rem*10)%n;
                digits++;
            }while(rem>1);
        }
        if (digits>longest) {map[i]=i;longest=digits;}
        else                map[i]=map[i-1];
    }
}
int main() {
    fillMap();
    int t;  scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;  scanf("%d",&n);
        printf("%d\n",map[n-1]);
    }
    return 0;
}
