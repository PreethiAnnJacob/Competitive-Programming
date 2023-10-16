//TC:6/6
/*
Given a*b=c and total no of digits=n
So |a|+|b|+|c|=n

We know, the lower and upper limit of product as:
|a|+|b|-1 <= |c| <= |a|+|b|
Adding |a|+|b|
2|a|+2|b|-1 <= n <= 2|a|+2|b|
Subtracting 2|a|
2|b|-1 <= n-2|a| <= 2|b|
Splitting to two inequalities
n-2|a| <= 2|b| and 2|b|-1 <= n-2|a|
(n/2) - 2|a| <= |b| and |b| <= (n+1)/2 - |a|
Combining
(n/2) - 2|a| <= |b| <= (n+1)/2 - |a|
So we have the lower and upper limit of multiplier |b| in terms of n and |a|

We know |a|>=1, |b|>=1, |c|>=1. Every item should have at least one digit.
We also know, since c=a*b, |c| should be >= |a|

n = |a|+|b|+|c|
Since |c|>=|a|:     n >= |a|+|b|+|a|
                    n >= 2|a|+|b|
Since |b|>=1:       n >= 2|a|+1
|a| <= (n-1)/2
Combining with |a|>=1
1 <= |a| <= (n-1)/2
So we have the lower and upper limit of multiplicand |a|

Idea is to traverse through |a| range to calculate a. Then calculate appropriate b and c.

*/

import java.io.*;
import java.util.*;

public class Solution {
    static int noOfDigits(int num)
    {   return ((int)Math.log10(num)+1);
    }
    static boolean isPandigital(int a,int b, int c, int n)
    {   int count[]=new int[n+1];
        Arrays.fill(count, 0);
        while(a>0)
        {   int d=a%10;
            if(d==0 || d>n)     return false;
            if (count[d]==1)    return false;
            count[d]++;
            a/=10;
        }
        while(b>0)
        {   int d=b%10;
            if(d==0 || d>n)     return false;
            if (count[d]==1)    return false;
            count[d]++;
            b/=10;
        }
        while(c>0)
        {   int d=c%10;
            if(d==0 || d>n)     return false;
            if (count[d]==1)    return false;
            count[d]++;
            c/=10;
        }
        return true;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int a_lower=1;
        int a_upper=(int)Math.pow(10,(n-1)/2);
        int pan[]=new int[a_upper+1];
        int panCount=0;
        for (int a=a_lower;a<=a_upper;a++)
        {   int b_lower = (int)Math.pow(10,(n/2.0 - 2*noOfDigits(a)));
            int b_upper = (int)Math.pow(10,((n+1)/2.0 - noOfDigits(a)));
            for(int b=b_lower;b<=b_upper;b++)
            {   int c=a*b;
                if (noOfDigits(a)+noOfDigits(b)+noOfDigits(c)==n)
                {   if (isPandigital(a,b,c,n))
                    {   //System.out.println(a+" "+b+" "+c);
                        boolean cIsUnique = true;
                        for(int i=0;i<panCount;i++)
                        {   if(pan[i]==c)   
                            {   cIsUnique = false;
                                break;
                            }
                        }
                        if (cIsUnique)  pan[panCount++]=c;
                    }
                }
            }
        }
        long sum=0;
        for(int i=0;i<panCount;i++)
            sum+=pan[i];
        System.out.println(sum);
    }
}

