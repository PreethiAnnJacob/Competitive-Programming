import java.util.*;
import java.io.*;
public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int T=sc.nextInt();
        for(int x=1; x<=T;x++){
            int N=sc.nextInt();
            int K=sc.nextInt();
            int P=sc.nextInt();
            int y=0;
            Stack<Integer> s[] = (Stack<Integer>[]) new Stack[N];
            for(int i=0;i<N;i++){
                s[i]=new Stack<Integer>();
                int tmp[]=new int[K];
                for(int j=0;j<K;j++){
                    tmp[j]=sc.nextInt();
                }
                for(int j=K-1;j>=0;j--){
                    s[i].push(tmp[j]);
                }
            }
            //for(int i=0;i<N;i++)
            while(P>0){
                int pick=-1;
                while(s[++pick].isEmpty());
                for(int i=0;i<N;i++){
                    if(!s[i].isEmpty())
                        if((Integer)s[i].peek()>(Integer)s[pick].peek())
                            pick=i;
                }
                System.out.print((Integer)s[pick].peek()+" ");
                y+=(Integer)s[pick].pop();
                P--;
            }
            System.out.println();
            System.out.println("Case "+x+": "+y);
        }
    }
}