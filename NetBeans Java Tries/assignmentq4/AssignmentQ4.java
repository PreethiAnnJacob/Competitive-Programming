/*4.Write a java program that creates two threads. The first thread should perform addition of two matrices.
Second thread should perform multiplication of two matrices. Ensure bad inputs and errors are handled appropriately.*/
package assignmentq4;
import java.io.*;
class AddThread extends Thread
{   
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    //Scanner sc=new Scanner(System.in));
    @Override
    public void run()
    {   try
            {System.out.println("Enter the number of rows and columns:");

            int r=Integer.parseInt(br.readLine());
            int c=Integer.parseInt(br.readLine());

            int a[][]=new int[r][c];
            int b[][]=new int[r][c];
            int sum[][]=new int[r][c];
            System.out.println("Enter the element into first array:");
            for (int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    a[i][j]=Integer.parseInt(br.readLine());
            System.out.println("Enter the element into second array:");
            for (int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    b[i][j]=Integer.parseInt(br.readLine());
            for (int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    sum[i][j]=a[i][j]+b[i][j];
            System.out.println("Sum array");
            for (int i=0;i<r;i++)
            {    for(int j=0;j<c;j++)
                    System.out.println(sum[i][j]+"\t");
                 System.out.println("\n");
            }
        }
        catch(IOException e)
        {}
    }
}
class MultiplyThread extends Thread
{   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    @Override
    public void run()
    {   try
        {   System.out.println("Enter the number of rows and columns of first array:");

            int r1=Integer.parseInt(br.readLine());
            int c1=Integer.parseInt(br.readLine());
            System.out.println("Enter the number of rows and columns of second array:");
            int r2=Integer.parseInt(br.readLine());
            int c2=Integer.parseInt(br.readLine());
            if(c1!=r2)
                System.out.println("Incompatible arrays for multiplication");
            else
            {   int a[][]=new int[r1][c1];
                int b[][]=new int[r2][c2];
                int p[][]=new int[r1][c2];
                System.out.println("Enter the element into first array:");
                for (int i=0;i<r1;i++)
                    for(int j=0;j<c1;j++)
                        a[i][j]=Integer.parseInt(br.readLine());
                System.out.println("Enter the element into second array:");
                for (int i=0;i<r2;i++)
                    for(int j=0;j<c2;j++)
                        b[i][j]=Integer.parseInt(br.readLine());
                for(int i=0;i<r1;i++)
                   for(int j=0;j<c2;j++)
                       for(int k=0;k<c2;k++)
                           p[i][j]+=a[i][k]*b[k][j];
                System.out.println("Product array");
                for (int i=0;i<r1;i++)
                {    for(int j=0;j<c2;j++)
                        System.out.println(p[i][j]+"\t");
                     System.out.println("\n");
                }
            }
        }
        catch(IOException e)
        {}
    }
}
public class AssignmentQ4 
{
    public static void main(String[] args) throws InterruptedException
    {
       AddThread d1=new AddThread();
        MultiplyThread d2=new MultiplyThread();
        Thread t1=new Thread(d1);
       Thread t2=new Thread(d2);
       t1.start(); 
       try {
          t1.join();
      } catch (InterruptedException ie) {
          throw new InterruptedException();
        }
        t2.start();
        try {
          t2.join();
        }
        catch (InterruptedException ie) {
          throw new InterruptedException();
        }
    }   
}
