/* Project Euler #5: Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible(divisible with no remainder) by all of the numbers from 1 to N?

Input Format
First line contains T that denotes the number of test cases. This is followed by T lines, each containing an integer, N.

Constraints
1<=T<=10
1<=N<=40

Output Format
Print the required answer for each test case.

Sample Input 0
2
3
10

Sample Output 0
6
2520

Explanation 0
You can check 6 is divisible by each of {1,2,3}, giving quotient of {6,3,2} respectively.
You can check 2520 is divisible by each of {1,2,3,4,5,6,7,8,9,10} giving quotient of {2520,1260,840,630,504,420,360,315,280,252} respectively.
*/

//Try 1: TC:5/5
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            for(int result=n;;result++)
            {   boolean found=true;
                for(int i=1;i<=n;i++)
                {   if (result%i!=0)
                    {   found=false;
                        break;
                    }   
                }
                if (found==true)
                {   System.out.println(result);
                    break;
                }
            }
        }
    }
}
