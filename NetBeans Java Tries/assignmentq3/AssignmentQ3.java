/*3.Write a program to create interface named customer. In this keep the methods called information(),show() and also maintain Tax rate.
Implement this interface in employee class and calculate the tax of the employee based on their Income.*/
package assignmentq3;

/*Interface customer*/
interface Customer
{   void information(String n,char ch,float inc);
    void show();
    double taxrate();
}

/*class Employee implements customer interface*/
class Employee implements Customer
{   String name;
    char sex;
    float income=0,tax=0;
    
    /*Function information()in Customer overrided*/
    @Override
    public void information(String n,char s,float inc)
    {   /*if(!(sex=='M' || sex=='m' || sex=='F' || sex=='f'))
        {    System.out.println("Invalid");
             System.exit(0);
        }*/
        name=n;
        sex=s;
        income=inc;
    }
    
    /*Function show() in Customer interface overrided */
    @Override
    public void show()
    {   System.out.println("Name:"+name);
        System.out.println("Sex:"+sex);
        System.out.println("Income:"+income);
        System.out.println("Tax rate:"+this.taxrate());
        System.out.println("Tax:"+income*this.taxrate());
    }
    
    /*Function taxrate maintains tax rate . Overriding taxrate() in Customer interface*/
    @Override
    public double taxrate()
    {   double tr=0;
        if (income<=190000)
            tr=0;
        else if(income<=200000)
        {   if(sex=='M' || sex=='m')
                tr=0.10;
            else
                tr=0;
        }
        else if(income<=500000)
        {   if(sex=='M' ||sex=='m')
                tr=0.20;
            else
                tr=0.10;
        }
        else
        {   if(sex=='M' || sex=='m')
                tr=0.25;
            else
                tr=0.20;
        }
        return tr;
    }
}


public class AssignmentQ3 {
    public static void main(String[] args) {
        Employee ob=new Employee();
        ob.information("Preethi",'F',300000);
        ob.show();
    }
    
}
