//Try 2: TC:0/6; All 6Failed due to TLE
// Tried to pre-calculate the values but failed.
import java.io.*;
import java.util.*;

public class Solution {
    static boolean curious[][][]=new boolean[10000][10000][3];
    static void calculateDigitFrequency(int numerator,int denominator,int n, int digCount[][])
    {   //Calculate digit frequency of numerator and denominator & common digit frequency for digits 0-9
        
        for(int i=0;i<3;i++)
            for(int j=0;j<10;j++)
                digCount[i][j]=0;   //Initialize digit frequency array to 0
        
        int numerator_copy=numerator;
        int denominator_copy=denominator;
        for(int i=0;i<n;i++)    //for n number of digits
        {   digCount[0][numerator_copy%10]++;
            digCount[1][denominator_copy%10]++;
            numerator_copy/=10;
            denominator_copy/=10;
        }
        //Ignoring digit 0 among common digit
        for(int i=1;i<=9;i++)   //common digit frequency
            digCount[2][i]=Math.min(digCount[0][i], digCount[1][i]);
    }
    static int removeDigit(int num,int i,int digit)
    {   //Given n-digit num. Return num without the i th occurence of digit from back
        //e.g. 7674 - Remove 2nd occurence of 7 from back result 674
        int newnum=0;
        int freqCountOfDigit=0;//frequency count of the given digit
        int pos=0;//position of digit in newnum
        while(num>0)
        {   int d=num%10;
            num/=10;
            if (d==digit)
            {   freqCountOfDigit++;
                if (freqCountOfDigit==i)   continue;
            }
            newnum=d*(int)Math.pow(10,pos++)+newnum;
        }
        return newnum;
    }
    static boolean isCurious(int numerator,int denominator,int n,int k,int digCount[][], int unreduced_numerator,int unreduced_denominator)
    {   if (numerator>=denominator) return false;
        if (k==0)
        {   double fraction1 = denominator*1.0/numerator;
            double fraction2 = unreduced_denominator*1.0/unreduced_numerator;
            if (fraction1==fraction2)   return true;
            else                        return false;
        }
        for (int digit=0;digit<=9;digit++)
        {   for (int h=1;h<=digCount[2][digit];h++)
            {   for (int i=1;i<=digCount[0][digit];i++)
                {   for (int j=1;j<=digCount[1][digit];j++)
                    {   int newNumerator=removeDigit(numerator,i,digit);//numerator without i th occurence of the digit
                        int newDenominator=removeDigit(denominator,j,digit);//denominator without jth occurence of digit
                        
                        //Updated DigCount for newNumerator and newDenominator and their common digits
                        int newDigCount[][]=new int[3][10];
                        for(int a=0;a<3;a++)
                            for(int b=0;b<10;b++)
                                newDigCount[a][b]=digCount[a][b];
                        newDigCount[0][digit]--;
                        newDigCount[1][digit]--;
                        newDigCount[2][digit]--;
                        
                        if (k==1 || k==2)  
                        {   if (isCurious(newNumerator,newDenominator,n-1,k-1,newDigCount,unreduced_numerator,unreduced_denominator))   
                                return true;
                        } 
                        else return curious[newNumerator][newDenominator][k-1];
                    }
                }
            }
        }
        return false;
    }
    static boolean isCurious(int numerator,int denominator,int n,int k,int digCount[][])
    {   return isCurious(numerator,denominator,n,k,digCount,numerator,denominator);
    }
    static void startup()
    {   for(int numerator=0;numerator<=9999;numerator++)
            for(int denominator=0;denominator<=9999;denominator++)
                for(int k=0;k<=3;k++)
                    curious[numerator][denominator][k]=false;
        
        for(int numerator=10;numerator<=9999;numerator++)
        {   int n=(int)Math.log10(numerator)+1;
            for(int denominator=numerator+1;denominator<=(int)Math.pow(10,n)-1;denominator++)
            {   for(int k=1;k<=3;k++)
                {   //Calculate digit frequency of numerator and denominator & common digit frequency for digits 0-9
                    int digCount[][]=new int[3][10]; 
                    calculateDigitFrequency(numerator,denominator,n,digCount); 
                    curious[numerator][denominator][k]=isCurious(numerator, denominator, n, k, digCount);
                }
            }
        }
    }
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long numeratorSum=0;                 // store output1
        long denominatorSum=0;               // store output2
        int min = (int)Math.pow(10,n-1);    //min n-digit number
        int max = (int)Math.pow(10,n)-1;    //max n-digit number
        
        //Iterate through numerator and denominator such that numerator is less than denominator
        for (int numerator=min;numerator<=max-1;numerator++)
        {   for(int denominator=numerator+1;denominator<=max;denominator++)
            {   if (curious[numerator][denominator][k])
                {   numeratorSum+=numerator;
                    denominatorSum+=denominator;
                }
            }
        }
        System.out.println(numeratorSum+" "+denominatorSum);
        sc.close();
    }
}
