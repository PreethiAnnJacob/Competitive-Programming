//TC:4/4
import java.io.*;
import java.util.*;

public class Solution {
    public static boolean isPrime(int num)
    {   if (num<2)  return false;
        for(int i=2;i*i<=num;i++)
            if(num%i==0)    return false;
        return true;
    }
    public static boolean isRightTruncatedPrime(int num)
    {   while(num>0)
        {   if(!isPrime(num))   return false;
            num/=10;
        }
        return true;
    }
    public static boolean isLeftTruncatedPrime(int num)
    {   int nd=(int)Math.log10(num)+1;
        while(num>0)
        {   if(!isPrime(num))   return false;
            num=num%(int)Math.pow(10,nd-1);
            nd--;
        }
        return true;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        long sum=0;
        for(int num=11;num<n;num+=2)
            if(isRightTruncatedPrime(num))
                    if(isLeftTruncatedPrime(num))
                        sum+=num;
        System.out.println(sum);
    }
}
