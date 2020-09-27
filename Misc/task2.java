import java.io.*;
class task2
{   public static void main()throws IOException
    {   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the number of rows:");
        int r=Integer.parseInt(br.readLine());
        String date[]=new String[r];
        int value[]=new int[r];
        for(int i=0;i<r;i++)
        {   System.out.print("Date["+i+"]:");
            date[i]=br.readLine();
            System.out.print("Value["+i+"]:");
            value[i]=Integer.parseInt(br.readLine());
        }
        System.out.print("Start Date(dd/mm/yyyy):");
        String startDate=br.readLine();
        System.out.print("End Date(dd/mm/yyyy):");
        String endDate=br.readLine();
        int dd1=Integer.parseInt(startDate.substring(0,2));
        int mm1=Integer.parseInt(startDate.substring(3,5));
        int yy1=Integer.parseInt(startDate.substring(6,10));
        int dd2=Integer.parseInt(endDate.substring(0,2));
        int mm2=Integer.parseInt(endDate.substring(3,5));
        int yy2=Integer.parseInt(endDate.substring(6,10));
        System.out.println("Filtered rows:");
        for(int i=0;i<r;i++)
        {   int dd=Integer.parseInt(date[i].substring(0,2));
            int mm=Integer.parseInt(date[i].substring(3,5));
            int yy=Integer.parseInt(date[i].substring(6,10));
            if( (yy1==yy && yy==yy2 && mm1==mm && mm==mm2 && dd1<=dd && dd<=dd2) |
                (yy1==yy && yy==yy2 && mm1<=mm && mm<=mm2 && mm1!=mm2) |
                (yy1==yy && yy!=yy2 && mm1==mm && dd1<=dd) |
                (yy1==yy && yy!=yy2 && mm1<mm) |
                (yy==yy2 && yy!=yy1 && mm==mm2 && dd<=dd2) |
                (yy==yy2 && yy!=yy1 && mm<=mm2) |
                (yy1<yy && yy<yy2))
                System.out.println(date[i]+"\t"+value[i]);
                
        }
    }
}