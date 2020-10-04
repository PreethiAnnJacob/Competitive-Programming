/**Assignment Q2
* Define Exceptions VowelException ,BlankException,ExitException.
* Write another class Test which reads a character from command line. 
* If it is a vowel, throw VowelException,
* if it is blank throw BlankException 
* and for a character 'X' throw an ExitException and terminate program. 
* For any other character, display “Valid character”. 
 */ 
package javaapplication1;
class VowelException extends Exception//custom exception -subclass of Exception class
{   char ch;
    VowelException(char ch)
    {   this.ch=ch;
    }
    public String to_String()//override to_String method
    {   return ("VowelException : Typed character is a vowel");
    }
    
}
package javaapplication1;
public class JavaApplication1 {
    void compute(char ch)
    {   try
        {   if (!(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'))
            {   throw new VowelException(ch);
            }
        }
        catch(VowelException e)
        {   System.out.println(e);
        }
    }
    public static void main(String[] args) {
        compute('A');
    }
    
}
