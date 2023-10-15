/* Project Euler #30: Digit Nth powers

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
1634=1**4+6**4+3**4+4**4
8208=8**4+2**4+0**4+8**4
9474=9**4+4**4+7**4+4**4
As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634+8208+9474=19316.

Find the sum of all the numbers that can be written as the sum of Nth powers of their digits.

Input Format
Input contains an integer N 

Constraints
3<=N<=6

Output Format
Print the answer corresponding to the test case.

Sample Input
4

Sample Output
19316
*/

// //Try 1: TC:3/4
// import java.io.*;
// import java.util.*;
// public class Solution {
//     public static void main(String[] args) {
//         Scanner in = new Scanner(System.in);
//         int n = in.nextInt();
//         int result=0;
//         for(int i=(int)Math.pow(10,n-1);i<=(int)Math.pow(10,n)-1;i++)
//         {   int num=i;
//             int sum=0;
//             while(num>0)
//             {   sum=sum+(int)Math.pow(num%10,n);
//                 num=num/10;
//             }
//             if (sum==i)
//                 result+=i;
//         }
//         System.out.println(result);
//     }
// }

// //Try 2:TC:3/4: Changing i start and end
// import java.io.*;
// import java.util.*;
// public class Solution {
//     public static void main(String[] args) {
//         Scanner in = new Scanner(System.in);
//         int n = in.nextInt();
//         long result=0;
//         for(long i=2;i<=(long)Math.pow(10,n);i++)
//         {   long num=i;
//             long sum=0;
//             while(num>0)
//             {   sum=sum+(long)Math.pow(num%10,n);
//                 num=num/10;
//             }
//             if (sum==i)
//             {   //System.out.print(i+" ");
//                 result+=i;
//             }
//         }
//         System.out.println(result);
//     }
// }

// //Try 3:TC:4/4: Changing i start and end
// import java.io.*;
// import java.util.*;
// public class Solution {
//     public static void main(String[] args) {
//         Scanner in = new Scanner(System.in);
//         int n = in.nextInt();
//         long result=0;
//         for(long i=2;i<=1000000;i++)
//         {   long num=i;
//             long sum=0;
//             while(num>0)
//             {   sum=sum+(long)Math.pow(num%10,n);
//                 num=num/10;
//             }
//             if (sum==i)
//             {   //System.out.print(i+" ");
//                 result+=i;
//             }
//         }
//         System.out.println(result);
//     }
// }

//Try 4:TC:4/4: Changing i start and end
import java.io.*;
import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long result=0;
        long maxI=n*(long)Math.pow(9,n);
        for(long i=2;i<=maxI;i++)
        {   long num=i;
            long sum=0;
            while(num>0)
            {   sum=sum+(long)Math.pow(num%10,n);
                num=num/10;
            }
            if (sum==i)
            {   //System.out.print(i+" ");
                result+=i;
            }
        }
        System.out.println(result);
    }
}


