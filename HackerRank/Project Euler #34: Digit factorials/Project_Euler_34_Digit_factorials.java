//Try 1: TC:5/5
  
import java.io.*;
import java.util.*;

public class Solution {
    static int fac[]=new int[10];
    public static long sumDigFac(int num)
    {   long sfd=0;
        while(num>0)
        {   sfd+=fac[num%10];
            num/=10;
        }
        return sfd;
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        fac[0]=1;
        for (int i=1;i<10;i++)
            fac[i]=i*fac[i-1];
        long sum = 0;
        for (int num=10;num<=n;num++)
        {   long sfd=sumDigFac(num);
            if (sfd%num==0)
                sum+=num;
        }
        System.out.println(sum);
    }
}
