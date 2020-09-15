/* TCS Ninja question asked for us.August 3 2019.
 * Find the difference between sum of odd digits and even digits of a number. The number can have upto 100 digits
 * Output:
 *      1546287935154628793515462879351546287935154628793515462879351546287935154628793515462879351546287935
 *      160
 *      
 *      12345
 *      3
 */
import java.io.*;
import java.math.BigInteger;
class OddlyEven
{   static BigInteger diff(BigInteger num)
    {   BigInteger pos=new BigInteger("0"),odd=new BigInteger("0"),even=new BigInteger("0");
        while(num.compareTo(new BigInteger("0"))>0)
        {   BigInteger d=new BigInteger(""+num.mod(new BigInteger("10")));
            if(pos.mod(new BigInteger("2")).compareTo(new BigInteger("0"))==0)
                odd=odd.add(d);
            else
                even=even.add(d);
            pos=pos.add(new BigInteger("1"));
            num=num.divide(new BigInteger("10"));
        }
        BigInteger value=odd.subtract(even).abs();
        return value;
    }
    public static void main(String[]args) throws IOException
    {   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        BigInteger num=new BigInteger(br.readLine());
        System.out.println(diff(num));
    }
}
