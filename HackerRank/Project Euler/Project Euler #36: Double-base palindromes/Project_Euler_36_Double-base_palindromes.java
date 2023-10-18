//Try 1: 1/15 failed due to TLE. That 1 failed because binary number string could not be contained in Long datatype.
// import java.io.*;
// import java.util.*;

// public class Solution {
//     public static long baseK(int num,int k)
//     {   String numk="";
//         while(num>0)
//         {   numk=num%k+numk;
//             num/=k;
//         }
//         return Long.parseLong(numk);
//     }
//     public static boolean isPalindrome(long num)
//     {   long revnum=0;
//         long num_copy=num;
//         while(num>0)
//         {   revnum = revnum*10+num%10;
//             num/=10;
//         }
//         return (revnum==num_copy);
//     }
//     public static void main(String[] args) {
//         /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
//         Scanner sc = new Scanner(System.in);
//         int n=sc.nextInt();
//         int k=sc.nextInt();
//         long sum=0;
//         for(int num=1;num<n;num++)
//             if (isPalindrome(num))
//                 if(isPalindrome(baseK(num,k)))
//                     sum+=num;
//         System.out.println(sum);
//     }
// }

//Try 2: TC:15/15 Passed
import java.io.*;
import java.util.*;

public class Solution {
    public static String baseK(int num,int k)
    {   String numk="";
        while(num>0)
        {   numk=num%k+numk;
            num/=k;
        }
        return numk;
    }
    public static boolean isPalindrome(String num)
    {   int numlength = num.length();
        for(int i=0;i<=numlength/2;i++)
            if(num.charAt(i)!=num.charAt(numlength-1-i))
                return false;
        return true;
    }
    public static boolean isPalindrome(long num)
    {   long revnum=0;
        long num_copy=num;
        while(num>0)
        {   revnum = revnum*10+num%10;
            num/=10;
        }
        return (revnum==num_copy);
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        long sum=0;
        for(int num=1;num<n;num++)
            if (isPalindrome(num))
                if(isPalindrome(baseK(num,k)))
                    sum+=num;
        System.out.println(sum);
    }
}
