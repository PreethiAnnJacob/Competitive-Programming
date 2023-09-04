/*Project Euler #19: Counting Sundays
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by , but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month between two dates(both inclusive)?

Input Format

The first line contains an integer T, i.e., number of test cases.
Each testcase will contain two lines
Y1 M1 D1 on first line denoting starting date.
Y2 M2 D2 on second line denoting ending date.

Constraints
1<=T<=100
1900<=Y1<=10^16
Y1<=Y2<=(Y1+1000)
1<=M1,M2<=12
1<=D1,D2<=31

Output Format
Print the values corresponding to each test case.

Sample Input
2
1900 1 1
1910 1 1
2000 1 1
2020 1 1

Sample Output

18
35
Explanation

For testcase 1, we have the following sundays :-

1 April 1900
1 July 1900
1 September 1901
1 December 1901
1 June 1902
1 February 1903
1 March 1903
1 November 1903
1 May 1904
1 January 1905
1 October 1905
1 April 1906
1 July 1906
1 September 1907 
1 December 1907
1 March 1908
1 November 1908
1 August 1909
*/

// //--------------------------Try 1: 3/7. TC#4,5,6,7 failed due to TLE. Score: 28.57/100
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// //Return yes if date1<=date2
// int isLE(long y1,int m1,int d1,long y2,int m2,int d2)
// {   if (y1<y2)   return 1;
//     if (y1==y2)
//     {   if(m1<m2)   return 1;
//         if(m1==m2)  {if (d1<=d2) return 1;}
//     }
//     return 0;
// }
// //Return next first-of-the-month date
// void next(long *y,int *m,int *d)
// {   *d=1;
//     if (*m==12) (*y)++;
//     *m=(*m%12) + 1;
// }
// //Return yes if YY is Leap Year
// int isLeapYear(long y)
// {   if (y%400==0)               return 1;
//     if (y%4==0 && y%100!=0)     return 1;
//     return 0;
// }
// //Return no of odd days for a given YY/MM
// int oddDaysMth(long y,int m)
// {   if (isLeapYear(y) && m==2)  return 1;
//     int oddMth[12]={3,0,3,2,3,2,3,3,2,3,2,3};
//     return oddMth[m-1];
// }
// //Calculate no of odd days for a given date
// int oddDays(long y,int m,int d)
// {   int odd=0;
//     int c=0;//c=years checked
//     int nc=y-1;//nc=years not checked
//     int oddCentury[4]={5,3,1,0};
//     for(int i=400;i>=100;i=i-100)
//     {   odd = (odd + oddCentury[(i/100)-1] * (nc/i) )%7;
//         c += nc - (nc%i);
//         nc = nc%i;
//     }
//     if (nc>0)
//     {   int leap=0;
//         for(int i=c+1;i<y;i++)
//             leap+=isLeapYear(i);
//         int nonleap=y-c-1-leap;
//         odd=(odd+nonleap+2*leap)%7;
//     }
//     for(int i=1;i<m;i++)
//         odd = (odd+oddDaysMth(y,i))%7;
//     odd=(odd+d)%7;
//     return odd;
// }
// int main() {
//     int t,m1,d1,m2,d2;  long y1,y2;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   scanf("%ld%d%d",&y1,&m1,&d1);
//         scanf("%ld%d%d",&y2,&m2,&d2);
//         int count=0;
//         if (d1!=1)  next(&y1,&m1,&d1);
//         while(isLE(y1,m1,d1,y2,m2,d2))
//         {   if(oddDays(y1,m1,d1)==0)    count++;
//             next(&y1,&m1,&d1);
//         }
//         printf("%d\n",count);
//     }
//     return 0;
// }
// //---------------------------------------------------------

// //------------------------------------- Try 2: 4/8 TC passed. Passed: TC#1,5,6,7. Failed due to Wrong answer: TC#0,2,3,4. Score:57.14/100.
// // Idk why this worked for these test cases. Anyway it is wrong 
// #include <stdio.h>
// #include <string.h>
// #include <math.h>
// #include <stdlib.h>
// //Return yes if date1<=date2
// int isLE(long y1,int m1,int d1,long y2,int m2,int d2)
// {   if (y1<y2)   return 1;
//     if (y1==y2)
//     {   if(m1<m2)   return 1;
//         if(m1==m2)  {if (d1<=d2) return 1;}
//     }
//     return 0;
// }
// //Return next first-of-the-month date
// void next(long *y,int *m,int *d)
// {   *d=1;
//     if (*m==12) (*y)++;
//     *m=(*m%12) + 1;
// }
// //Return yes if YY is Leap Year
// int isLeapYear(long y)
// {   if (y%400==0)               return 1;
//     if (y%4==0 && y%100!=0)     return 1;
//     return 0;
// }
// //Return no of odd days for a given YY/MM from YY/Jan
// int oddDaysMth(long y,int m)
// {   int oddMthNonLeap[12]={3,3,6,1,4,6,2,5,0,3,5,1};
//     int oddMthLeap[12]={3,4,0,2,5,0,3,6,1,4,6,2};
//     if (isLeapYear(y))  return oddMthLeap[m-1];
//     else                return oddMthNonLeap[m-1];
// }
// //Calculate no of odd days for a given date
// int oddDays(long y,int m,int d)
// {   int odd=0;
//     int nc=y-1;//nc=years not checked
//     int oddCentury[4]={5,3,1,0};
//     for(int i=400; i>=100 && nc >=i ;i=i-100)                //Wrong here: nc>=i checking within for loop itself. e.g. 1700=1600+100. 100 is not checked since nc>=i fails when i=300
//     {   odd = (odd + oddCentury[(i/100)-1] * (nc/i) )%7;
//         nc = nc%i;
//     }
//     if (nc>0)
//     {   int leap = nc/4;
//         odd=(odd+nc+leap)%7;
//     }
//     if (m>1)    odd = (odd+oddDaysMth(y,m-1))%7;
//     odd=(odd+d)%7;
//     return odd;
// }
// int main() {
//     int t,m1,d1,m2,d2;  long y1,y2;
//     scanf("%d",&t);
//     for(int a0=0;a0<t;a0++)
//     {   scanf("%ld%d%d",&y1,&m1,&d1);
//         scanf("%ld%d%d",&y2,&m2,&d2);
//         int count=0;
//         if (d1!=1)  next(&y1,&m1,&d1);
//         while(isLE(y1,m1,d1,y2,m2,d2))
//         {   if(oddDays(y1,m1,d1)==0)    count++;
//             next(&y1,&m1,&d1);
//         }
//         printf("%d\n",count);
//     }
//     return 0;
// }
// //---------------------------------------Try 2 end

//--------------------------------------Try 3: 8/8 TC passed. Score:100/100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Return yes if date1<=date2
int isLE(long y1,int m1,int d1,long y2,int m2,int d2)
{   if (y1<y2)   return 1;
    if (y1==y2)
    {   if(m1<m2)   return 1;
        if(m1==m2)  {if (d1<=d2) return 1;}
    }
    return 0;
}
//Return next first-of-the-month date
void next(long *y,int *m,int *d)
{   *d=1;
    if (*m==12) (*y)++;
    *m=(*m%12) + 1;
}
//Return yes if YY is Leap Year
int isLeapYear(long y)
{   if (y%400==0)               return 1;
    if (y%4==0 && y%100!=0)     return 1;
    return 0;
}
//Return no of odd days for a given YY/MM from YY/Jan
int oddDaysMth(long y,int m)
{   int oddMthNonLeap[12]={3,3,6,1,4,6,2,5,0,3,5,1};
    int oddMthLeap[12]={3,4,0,2,5,0,3,6,1,4,6,2};
    if (isLeapYear(y))  return oddMthLeap[m-1];
    else                return oddMthNonLeap[m-1];
}
//Calculate no of odd days for a given date
int oddDays(long y,int m,int d)
{   int odd=0;
    long nc=y-1;//nc=years not checked
    int oddCentury[4]={5,3,1,0};
    for(int i=400; i>=100 ;i=i-100)
    {   if (nc>=i)
        {   odd = (odd + oddCentury[(i/100)-1] * (nc/i) )%7;
            nc = nc%i;
        }
    }
    if (nc>0)
    {   int leap = nc/4;
        odd=(odd+nc+leap)%7;
    }
    if (m>1)    odd = (odd+oddDaysMth(y,m-1))%7;
    odd=(odd+d)%7;
    return odd;
}
int main() {
    int t,m1,d1,m2,d2;  long y1,y2;
    scanf("%d",&t);
    for(int a0=0;a0<t;a0++)
    {   scanf("%ld%d%d",&y1,&m1,&d1);
        scanf("%ld%d%d",&y2,&m2,&d2);
        int count=0;
        if (d1!=1)  next(&y1,&m1,&d1);
        while(isLE(y1,m1,d1,y2,m2,d2))
        {   if(oddDays(y1,m1,d1)==0)    count++;
            next(&y1,&m1,&d1);
        }
        printf("%d\n",count);
    }
    return 0;
}

//---------------------------------------------Try 3 end
