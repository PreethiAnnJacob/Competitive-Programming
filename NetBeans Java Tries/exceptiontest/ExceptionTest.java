package votingage;
import java.lang.System;
import java.lang.Exception;
import java.io.IOException;

class VowelException extends Exception {}
class BlankException extends Exception {}
class ExitException extends Exception {}

class ExceptionTest {
 BufferedReader br=new BufferedReader (new InputStreamReader(System.in)); 
 public static void main(String args[]) {
  boolean finished = false;
  //do {
   try {
    processUserInput();
   }catch (VowelException x) {
    System.out.println("A vowel exception occurred.");
   }catch (BlankException x) {
    System.out.println("A blank exception occurred.");
   }catch (ExitException x) {
    System.out.println("An exit exception occurred.");
    finished = true;
   }finally {
    System.out.println("This is the finally clause.\n");
   }
  //} while(!finished);
 }
 static void processUserInput() throws VowelException, BlankException, 
  ExitException {
  System.out.print("Enter a character: "); 
  
  System.out.flush();
  char ch;
  try {
   ch=br.read();
  } catch (IOException x) {
   System.out.println("An IOException occurred."); 
   return;
  }
  switch(ch) {
   case 'A':
   case 'E':
   case 'I':
   case 'O':
   case 'U':
    throw new VowelException();
   case ' ':
    throw new BlankException();
   case 'X':
    throw new ExitException();
  }
 }
}
