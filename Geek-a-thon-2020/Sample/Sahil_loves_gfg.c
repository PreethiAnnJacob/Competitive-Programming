/*Sahil loves gfg Submissions: 18324   Accuracy: 40.41%   Max. Score: 30
Problems
Sahil is done with his internship and now it's time to attend Geeks Classes to enhance knowledge of Data Structures. However, to join this class, he has been given a task to complete. The task is to count the occurrences of "gfg" in the given string, and if he completes this task, he qualifies for Geeks Classes. But, Sahil is facing some problem in solving this task, so help him.

Input :
First line of input contains "T" testcases. Next "T" lines contains Strings with lowercase characters.

Output :
For each testcase, output the count the ccurrences of "gfg"(continuous) present in string.

Constraints :
1 <= T <= 10
1<= length_of_string <= 100

Example :
Input :
2
geefgfgksforgfgeeks
dsajslsdlsfgf
Output :
2
-1

Explanation :
#Test Case 1: In the first testcase, "gfg" occurs two times in the String. First ccurrence starts at index 4 and next starts at 12.
#Test Case 2: In second testcase, there is no occurences of "gfg" in given string. So, it returned -1.

C (gcc 5.4)*/

#include <stdio.h>
#include <string.h>
int main() {
	int t;
	scanf("%d",&t);
	int arr[10];
	for(int i=0;i<t;i++){
	    char str[102];
	    int count=0;
	    scanf("%s",str);
      int l=strlen(str);//If directly used in for loop, results in segmentation fault. So create a variable l and then use within the loop
	    for(int j=0;j<=(l-3);j++){
	        if((str[j]=='g') & (str[j+1]=='f') & (str[j+2]=='g'))
	            count++;
	    }
	    if (count==0)arr[i]=-1;
	    else    arr[i]=count;
	}
	for(int i=0;i<t;i++){
	    printf("%d",arr[i]);
	    if(i!=t-1)  printf("\n");
	}
	return 0;
}

/*Correct Answer.Correct Answer
Execution Time:0.01*/
