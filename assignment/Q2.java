/*2.	Define Exceptions VowelException ,BlankException,ExitException.
        Write another class Test which reads a character from command line.
        If it is a vowel, throw VowelException,
        if it is blank throw BlankException
        and for a character 'X' throw an ExitException and terminate program. 
        For any other character, display “Valid character”.*/

package assignment;

/*Three Custom Exception classes*/
class VowelException extends Exception
{   @Override
    public String toString()
    {   return("\nVowelException\n");
    }
}
class BlankException extends Exception
{   @Override
    public String toString()
    {   return("\nBlankException\n");
    }
}
class ExitException extends Exception
{   @Override
    public String toString()
    {   return("\nExitException\n");
    }
}
        
public class Q2 
{   static void compute(char ch)
    {   try
        {   if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')//if vowel
                throw new VowelException();
        else if(ch==' ')//If blank
                throw new BlankException();
        else if(ch=='X')//If exit
                throw new ExitException();
        else 
                System.out.println("Valid character");
        }
        catch(VowelException e)
        {   System.out.println(e);
        }
        catch(BlankException e)
        {   System.out.println(e);
        }
        catch(ExitException e)
        {   System.out.println(e);
            System.exit(0);
        }
    }
    public static void main(String args[])
    {   char ch=args[0].charAt(0);
        System.out.println("Entered character : "+ch);
        compute(ch);
    }
}
