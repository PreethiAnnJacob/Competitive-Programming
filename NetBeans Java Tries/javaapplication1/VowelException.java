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

