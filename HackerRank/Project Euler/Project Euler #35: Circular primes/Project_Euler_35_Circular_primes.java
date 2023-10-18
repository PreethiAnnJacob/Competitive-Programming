//Try 1: TC:6/6

import java.io.*;
import java.util.*;

public class Solution {
    public static boolean isPrime(int num)
    {   for(int i=2;i*i<=num;i++)
            if (num%i==0)   return false;
        return true;
    }
    public static boolean isCircularPrime(int num)
    {   int nd=(int)Math.log10(num)+1;
        for(int count=1;count<=nd;count++)
        {   if (! isPrime(num)) return false;
            num=(num%10)*(int)Math.pow(10,nd-1)+(num/10);
        }
        return true;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long sum=2;
        for (int num=3;num<n;num+=2)
            if (isCircularPrime(num))   
                sum+=num;
        System.out.println(sum);
    }
}
