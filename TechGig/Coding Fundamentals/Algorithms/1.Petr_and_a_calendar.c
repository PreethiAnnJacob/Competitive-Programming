/*
Petr and a calendar (100 Marks)
Petr wants to make a calendar for current month. For this purpose he draws a table in which columns correspond to weeks (a week is seven consequent days from Monday to Sunday), rows correspond to weekdays, and cells contain dates. For example, a calendar for January 2017 should look like on the picture:

Petr wants to know how many columns his table should have given the month and the weekday of the first date of that month? Assume that the year is non-leap.


Input Format
You will be given a function with two integers m and d as arguments.


Constraints
1 < = m < = 12
1 < = d < = 7


Output Format
You need to return single integer: the number of columns the table should have..


Sample TestCase 1
Input
1
7
Output
6
*/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *a[])
{	int m,d;
	scanf("%d%d",&m,&d);
	int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int ans=ceil((md[m]-(8-d))/7.0);
	printf("%d",ans+1);
}
