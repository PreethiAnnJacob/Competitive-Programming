/* Project Euler #10: Summation of primes

The sum of the primes below 10 is 2+3+5+7=17.

Find the sum of all the primes not greater than given N.

Input Format

The first line contains an integer T i.e. number of the test cases.
The next T lines will contains an integer N.

Constraints
1<=T<=10**4
1<=N<=10**6

Output Format
Print the value corresponding to each test case in separate line.

Sample Input 0
2
5
10

Sample Output 0
10
17

Explanation 0
For N=5, we have primes as {2,3,5} and the sum is 10.
For N=10, we have primes as {2,3,5,7} and the sum is 17.

*/

//Try 1: TC:5/8; e testcase error due to TLE
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static boolean isPrime(int n)
    {   for(int i=2;i<=n/2;i++)
            if (n%i==0)    return false;
        return true;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int sum=0;
            for(int i=2;i<=n;i++)
                if (isPrime(i)) 
                    sum=sum+i;
            System.out.println(sum);
        }
    }
}
