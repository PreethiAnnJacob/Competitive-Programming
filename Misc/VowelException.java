/* Java Assignment Q2   
 * Define Exceptions VowelException ,BlankException,ExitException.
 * Write another class Test which reads a character from command line. 
 * If it is a vowel, throw VowelException,
 * if it is blank throw BlankException 
 * and for a character 'X' throw an ExitException and terminate program. 
 * For any other character, display “Valid character”.
 */

class VowelException extends Exception//custom exception -subclass of Exception class
{   char ch;
    VowelException(char ch)
    {   this.ch=ch;
    }
    public String to_String()//override to_String method
    {   return (ch+" is a vowel\n");
    }
}
class BlankException extends Exception  
{   char ch;
    BlankException(char ch)
    {   this.ch=ch;
    }
    public String to_String()
    {   return ("Blank character\n");
    }
}
class ExitException extends Exception  
{   char ch;
    ExitException(char ch)
    {   this.ch=ch;
    }
    public String to_String()
    {   return ("Exit program\n");
    }
}
class Test
{   char ch=' ';
    static void compute(char ch)
    {
    }
    public static void main(String args[])
    {   ch=args[0].charAt(0);
        
    }
}