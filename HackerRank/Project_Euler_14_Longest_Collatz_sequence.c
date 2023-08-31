/* Project Euler #14: Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:
If n is even, n->n/2
If n is odd, n->3n+1

Using the rule above and starting with 13, we generate the following sequence:
13->40->20->10->5->16->8->4->2->1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number,<=N produces the longest chain? If many possible such numbers are there print the maximum one.

Note: Once the chain starts the terms are allowed to go above N.

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integers N.

Constraints
1<=T<=10^4
1<=N<=5x10^6

Output Format

Print the values corresponding to each test case.

Sample Input

3
10 
15
20
Sample Output

9
9
19
Explanation

Collatz sequence for n=9 is,
9->28->14->7->22->11->34->17->52->26->13->40->20->10->5->16->8->4->2->1
containing  steps and is the longest for n<=10
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Try 1: 5/13 passed. Testcase#5-12 shows TLE
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;
        scanf("%d",&n);
        int maxcount=1,maxstart=1;
        for(int i=n;i>=2;i--)
        {   int count=1;//number itself
            int seq=i;//printf("%d ",seq);
            while(seq>1)
            {   if(seq%2==0)    seq=seq/2; 
                else            seq=3*seq+1;        
                count++;//printf("%d ",seq);
            }
            if(count>maxcount)  {maxcount=count;maxstart=i;}
            //printf("%d \n",count);
        }
        printf("%d\n",maxstart);
    }   
    return 0;
}
