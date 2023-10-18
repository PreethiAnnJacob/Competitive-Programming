/*Project_Euler_4_Largest_palindrome_product.java - Medium

A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101 = 143 x 707.

Find the largest palindrome made from the product of two 3-digit numbers which is less than N.

Input Format

First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1<=T<=100
101101<N<1000000

Output Format
Print the required answer for each test case in a new line.

Sample Input 0
2
101110
800000

Sample Output 0
101101
793397

Explanation 0
101101 is product of 143 and 707.
793397 is product of 869 and 913.
*/

//Try 1: TC:4/4, Score:100/100
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static int reverse(int n)
    {   int rev=0;
        while(n>0)
        {   rev = 10*rev +n%10;
            n=n/10;
        }
        return rev;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int result = 0;
            for(n=n-1;n>=101101;n--)
            {   if (n==reverse(n))
                {   for(int f1=100;f1<=999;f1++)
                    {   if (n%f1==0)
                        {   int f2=n/f1;
                            if (n%f2==0 && f2>=100 && f2<=999)   
                                if (n>result)   result=n;
                        }
                    }
                    if (result!=0)  break;
                }
            }
            System.out.println(result);
        }
    }
}
