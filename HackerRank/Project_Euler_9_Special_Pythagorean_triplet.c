/*Project Euler #9: Special Pythagorean triplet
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);

        //Try 1: 5/8 TC passed. TC#5,6,7 failed due to TLE.
        int maxabc=-1;
        for(int c=n-3;c>=3;c--)
        {   for(int b=n-c-1;b>=2;b--)
            {   int a=n-(b+c);
                if (a*a+b*b==c*c)   
                {   maxabc=a*b*c;
                    a=b=1;  //To break from both loops
                    break;
                }
            }
        }
        printf("%d\n",maxabc);
        
        int maxabc=-1;
        for(int c=n-3;c>=3;c--)
        {   for(int b=n-c-1;b>=2;b--)
            {   if (c>b)
                {   int a=n-(b+c);
                    if(b>a &&  (a*a+b*b==c*c) && (a*b*c>maxabc))    maxabc=a*b*c;
                }
            }
        }
        printf("%d\n",maxabc);

    }
    return 0;
}
