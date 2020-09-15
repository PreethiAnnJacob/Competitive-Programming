import java.io.*;
import java.util.*;
class Prefix
{   
    static int priority(String op)
    {   if(op.equals("PLUS"))
            return 1;
        else if(op.equals("MINUS"))
            return 2;
        else if(op.equals("MULTIPLY"))
            return 3;
        else if(op.equals("DIVIDE"))
            return 4;
        return 0;
    }
    static String infixToPostfix(String infix)
    {   String word;
        //System.out.println(infix);
        infix=infix.toUpperCase();
        String in[]=infix.split(" ",100);
        //System.out.println(infix);
        Stack<String> operators = new Stack<String>(); 
        Stack<String> operand = new Stack<String>();
        for(int i =0;i<in.length;i++)
        {   //System.out.println(in[i]);
            word=in[i];
            if (word.equals("PLUS")||word.equals("MINUS")||word.equals("MULTIPLY")||word.equals("DIVIDE"))
            {   //System.out.println(priority(word));
                if(!operators.empty())
                {   //System.out.println(operators.peek());
                    //System.out.println(priority(word)>priority(operators.peek()));
                    if(priority(word)>priority(operators.peek()))
                    {   operators.push(word);
                        //System.out.println("operators: " + operators);
                    }
                    else
                    {   String operand2=operand.peek();operand.pop();
                        String operand1=operand.peek();operand.pop();
                        String operator=word;//operators.pop();
                        operand.push(operator+" "+operand1+" "+operand2);
                    }
                }
                else 
                    operators.push(word);
            }
            else
                operand.push(word);
            //System.out.println("operators: " + operators);
            //System.out.println("operand: " + operand);
        }
        while(!operators.empty())
        {   String operand2=operand.peek();operand.pop();
            String operand1=operand.peek();operand.pop();
            String operator=operators.peek();operators.pop();
            operand.push(operator+" "+operand1+" "+operand2);
        }
    
        //System.out.println("operators: " + operators);
        //System.out.println("operand: " + operand);
        return operand.peek();
    }
    static float evaluatePrefix(String prefix)
    {   prefix=prefix.toUpperCase();
        String pre[]=prefix.split(" ",100);
        Stack<String> operand = new Stack<String>();
        for(int i=pre.length-1;i>=0;i--)
        {   String word=pre[i];
            if (word.equals("PLUS")||word.equals("MINUS")||word.equals("MULTIPLY")||word.equals("DIVIDE"))
            {   float op1=Float.parseFloat(operand.peek());operand.pop();
                float op2=Float.parseFloat(operand.peek());operand.pop();
                float ans=0;
                if(word.equals("PLUS"))
                    ans=op1+op2;
                else if(word.equals("MINUS"))
                    ans=op1-op2;
                else if(word.equals("MULTIPLY"))
                    ans=op1*op2;
                else if(word.equals("DIVIDE"))
                    ans=op1/op2;
                operand.push(""+ans);
            }
            else
                operand.push(word);
        }
        return Float.parseFloat(operand.peek());
    }
    public static void main() throws IOException
    {   BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        String infix=br.readLine();
        String prefix=infixToPostfix(infix);
        System.out.println(prefix);
        float value=evaluatePrefix(prefix);
        System.out.println(value);
    }
}

/*Output:
2 plus 18 multiply 3 divide 9
PLUS 2 MULTIPLY 18 DIVIDE 3 9
8.0
*/
