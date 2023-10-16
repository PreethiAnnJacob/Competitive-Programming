//Try 1: TC:9/9
import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int coins[]={1,2,5,10,20,50,100,200};
        long ways[]=new long[100001];
        ways[0]=1;
        for(int i=0;i<8;i++)
        {   int coin=coins[i];
            for (int j=coin;j<=100000;j++)
                ways[j]=(ways[j]+ways[j-coin])%(1000000007);
                //Say now i index points to 5, then ways[j] says in how many ways total=j is possible with {1,2,5} pences alone
        }
        int t = in.nextInt();
        for(int a0=0;a0<t;a0++)
        {   int n = in.nextInt();
            System.out.println(ways[n]);
        }
    }
}
