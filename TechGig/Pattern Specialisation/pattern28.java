/*
Pattern Problem - 28 (100 Marks)
You need to take an integer input and then draw the pattern according to it. Say for example if you enter 5 then, the pattern should be like this-

            A
         A B
      A B C
   A B C D
A B C D E 

Input Format
You will take an integer input n from stdin.

Constraints
1 <= n <= 26

Output Format
Your output should be the pattern according to the input which you had entered. 

Sample TestCase 1
Input
5
Output
A
      A B
    A B C
  A B C D
A B C D E
*/

import java.io.*;
import java.util.*;
public class CandidateCode {
   public static void main(String args[] ) throws Exception {
      BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
      int n=Integer.parseInt(br.readLine());
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n-i;j++)
            System.out.print("  ");
         for(int j=1;j<=i;j++){
            if(j!=i)
               System.out.print((char)('A'+j-1)+" ");
            else
               System.out.print((char)('A'+j-1));
         }
         System.out.println();
      }
   }
}
