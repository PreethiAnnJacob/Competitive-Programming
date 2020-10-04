/*Java Assignment:Set B(25-48):Q2
Define Exceptions VowelException ,BlankException,ExitException.
Write another class Test which reads a character from command line. 
If it is a vowel, throw VowelException,
if it is blank throw BlankException
and for a character 'X' throw an ExitException and terminate program.
For any other character, display “Valid character”.
*/
package javaassignment2;
class VowelException extends Exception//VowelException : custom exception - subclass of Exception
{   char ch;
    VowelException(char c)//Constructor
    {   ch=c;
    }
    @Override
    public String toString()//overriding toString() of Throwable class
    {   return("\nVowelException : Entered character :"+ch+" is a vowel\n");
    }
}
class BlankException extends Exception//BlankException : custom exception - subclass of Exception
{   char ch;
    BlankException(char c)//Constructor
    {   ch=c;
    }
    @Override
    public String toString()//overriding toString() of Throwable class
    {   return("\nBlankException : Entered character is blank\n");
    }
}
class ExitException extends Exception//ExitException : custom exception - subclass of Exception
{   char ch;
    ExitException(char c)//Constructor
    {   ch=c;
    }
    @Override
    public String toString()//overriding toString() of Throwable class
    {   return("\nExitException : Entered character is X\n");
    }
}
class TestDemo
{   static void compute(char ch)//throws VowelException,BlankException,ExitException//static function can be called directly without object from within the class
    {   try
        {   if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E'|| ch=='I' || ch=='O' || ch=='U')
                throw new VowelException(ch);//calling constructor
            else if(ch==' ')
                throw new BlankException(ch);
            else if(ch=='X')
                throw new ExitException(ch);
            else 
                System.out.println(ch+" is Valid character");
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
}

public class Test
{   public static void main(String[] args)//throws IOException
    {   char ch=args[0].charAt(0);
        System.out.println(ch);
        TestDemo.compute(ch);
    }
}
