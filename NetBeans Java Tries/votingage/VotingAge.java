package votingage;
public class VotingAge extends Exception
{   int detail;
    public VotingAge(int a)
    {   detail=a; 
    }
    public String toString()//override to_String method
    {   return ("\nVoting age Except age < "+detail+" not valid");
    }
    static void compute(int a)
    {   try
        {   if(a<18)
                throw new VotingAge(a);
            else
                System.out.println("Valid age");
        }
        catch(VotingAge e)
        {   System.out.println("Except Age "+e);
        }
    }
    
}
class demo
{   public static void main(String args[])
    {   VotingAge.compute(16);
        VotingAge.compute(18);
    }  
}

// A Class that uses above MyException

/*public class VotingAge
{
    // Driver Program
    public static void main(String args[])
    {   int age=12;
        try
        {   if (age<18)
            // Throw an object of user defined exception
            throw new MyException();
        }
        catch (MyException ex)
        {
            System.out.println("Caught");

            // Print the message from MyException object
            System.out.println(ex.getMessage());
        }
    }
}*/
