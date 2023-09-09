/*Project Euler #25: N-digit Fibonacci number -  EASY
The Fibonacci sequence is defined by the recurrence relation:
  Fn=Fn-1+Fn-2, where F1=1 and F2=1.
Hence the first 12 terms will be: F1=1  F2=1 F3=2 F4=3 F5=5 F6=8 F7=13 F8=21 F9=34 F10=55 F11=89 F12=144
The 12th term, F12, is the first term to contain three digits.
What is the first term in the Fibonacci sequence to contain N digits?

Input Format

The first line contains an integer T , i.e., number of test cases.
Next T lines will contain an integer N.

Constraints
1<=T<=5000
2<=N<=5000

Output Format

Print the values corresponding to each test case.

Sample Input

2
3
4
Sample Output

12
17
*/

//Try 1: TC:2/4 Rest failed due to Time Limit Exceeded.
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// int main() {
//     int t;  scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;   scanf("%d",&n);
//         unsigned long long a=1,b=1,c=1;int count=2;
//         unsigned long long nd=(log10(c)+1);//printf("nd=%d ",nd);
//         while(nd<n)
//         {   c=a+b;count++;//printf("c=%d ",c);
//             nd=(log10(c)+1);
//             a=b;b=c;
//         }
//         printf("%d\n",count);
//     }
//     return 0;
// }

//Try 2: TC:3/4 Rest failed due to TLE
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>

// //Return c=a+b with c_size. a<=b.
// int add(int a[],int a_size,int b[],int b_size,int c[])
// {   int carry=0; int i;
//     for(i=0;i<b_size;i++)
//     {   int temp = b[i]+carry;
//         if (i<a_size)   temp = temp+a[i];
//         if (temp>9) {c[i]=temp%10;  carry=temp/10;  }
//         else        {c[i]=temp;     carry=0;        }
//     }
//     int c_size=b_size;
//     if (carry>0)    {   c[b_size]=carry;    c_size++;   }
//     return c_size;
// }
// //Function to do a=b
// int copy(int a[],int b[],int b_size)
// {   for(int i=0;i<b_size;i++)
//         a[i]=b[i];
//     return b_size;
// }
// int main() {
//     int t;  scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   int n;   scanf("%d",&n);
//         int a[500]={1},b[5000]={1},c[5000];
//         int a_size=1,b_size=1;
//         int count=2;
//         int c_size=1;
//         while(c_size<n)
//         {   c_size=add(a,a_size,b,b_size,c);
//             count++;
//             a_size=copy(a,b,b_size);
//             b_size=copy(b,c,c_size);
//         }
//         printf("%d\n",count);
//     }
//     return 0;
// }

//Try 3: TC: 4/4
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int map[5001]={};

//Return c=a+b with c_size. a<=b.
int add(int a[],int a_size,int b[],int b_size,int c[])
{   int carry=0; int i;
    for(i=0;i<b_size;i++)
    {   int temp = b[i]+carry;
        if (i<a_size)   temp = temp+a[i];
        if (temp>9) {c[i]=temp%10;  carry=temp/10;  }
        else        {c[i]=temp;     carry=0;        }
    }
    int c_size=b_size;
    while (carry>0)    {   c[b_size]=carry%10;    c_size++;   carry=carry/10;}  //if instead of while also works
    return c_size;
}
//Function to do a=b
int copy(int a[],int b[],int b_size)
{   for(int i=0;i<b_size;i++)
        a[i]=b[i];
    return b_size;
}
void fillMap()
{   int a[10000]={1},b[10000]={1},c[10000];
    int a_size=1,b_size=1,c_size=1;
    int count=2;
    map[1]=1;  int mapindex=2;
    while(mapindex<=5000)
    {   c_size=add(a,a_size,b,b_size,c);
        count++;
        if (map[mapindex]==0 && mapindex==c_size)   map[mapindex++]=count;
        a_size=copy(a,b,b_size);
        b_size=copy(b,c,c_size);
    }
}
int main() {
    fillMap();
    int t;  scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   int n;   scanf("%d",&n);
        printf("%d\n",map[n]);
    }
    return 0;
}
