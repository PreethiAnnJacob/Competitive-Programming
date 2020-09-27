import java.io.*;
class Task1
{   public static void main()throws IOException
    {   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int noOfDays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
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
        System.out.println("Display dates:");
        for(int y=yy1;y<=yy2;y++)
        {   int startm,endm;
            if(y==yy1) startm=mm1; else startm=1;
            if(y==yy2) endm=mm2; else endm=12;
            for(int m=startm;m<=endm;m++)
            {   int startd,endd;
                if(m==mm1) startd=dd1; else startd=1;
                if(m==mm2) endd=dd2; else endd=noOfDays[m];
                for(int i=startd;i<=endd;i++)
                System.out.println(i+"/"+m+"/"+y);      
            }
        }
    }
}