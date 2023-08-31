'''Project Euler #13: Large sum
Work out the first ten digits of the sum of N 50-digit numbers.

Input Format
First line contains N, next N lines contain a 50 digit number each.

Constraints
1<=N<=10^3

Output Format
Print only first 10 digit of the final sum

Sample Input

5
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
Sample Output

2728190129
Explanation

Summing the numbers we get 27271901298203036131464767301043585006837989465343, first 10 digits are 2727190129.
'''

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 1 done in Python.

//Try 2: in C: 0/3 cases passed. Wrong answer. Note: Value of sum is too much for any integer datatype to handle.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d",&n);
    unsigned long long sum=0;
    for(int a0=0;a0<n;a0++)
    {   char str[50];
        scanf("%s",str);
        for(int i=0;i<50;i++)
            sum=sum+(str[i]-'0');
    }
    unsigned long long totaldigits=log10(sum)+1;
    unsigned long long result = sum/pow(10,(totaldigits-10));
    printf("%llu",result); 
    return 0; 
}
