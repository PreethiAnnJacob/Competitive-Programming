//TC:6/6
import java.io.*;
import java.util.*;

public class Solution {
    public static boolean isDigitRepeated(String num)
    {   int digCount[]=new int[10];
        Arrays.fill(digCount,0);
        for(int i=0;i<num.length();i++)
        {   if (digCount[num.charAt(i)-'0']>0)  return true;
            digCount[num.charAt(i)-'0']++;
        }
        return false;
    }
    //input num is exactly of k size and there is no digit repetition
    public static boolean isPanKDigital(String num, int k)
    {   int digCount[]=new int[10];
        Arrays.fill(digCount,0);
        for(int i=0;i<k;i++)
           if (num.charAt(i)-'0'==0 || num.charAt(i)-'0'>k)  
                return false;
        return true;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        for(int m=2;m<n;m++)
        {   String concat="";
            for(int i=1;;i++)
            {   concat=concat+(m*i);
                if (isDigitRepeated(concat))    break;
                int nd=concat.length();
                if (nd>=k)
                {   if (nd==k)  
                        if (isPanKDigital(concat,k))
                            System.out.println(m);  
                    break;
                }
            }
        }
    }
}
