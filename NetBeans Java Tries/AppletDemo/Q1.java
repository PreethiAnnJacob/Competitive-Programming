/*1.	Write an applet that shows different shapes(rectangle, triangle, circle etc) on different parts of the applet window 
        and when mouse points to a shape, the status bar should show the shape of  the corresponding object. */

package appletdemo;

import java.applet.Applet;
import java.awt.*;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;

/*<applet code = "appletdemo.Q1" width="300" height="300"> </applet>*/

public class Q1 extends Applet implements MouseMotionListener
{   Label l;
    TextField t1,t2;
    
    @Override
    public void init()
    {   l=new Label ("Move over the shapes");//Label : Move over shapes
        add(l);
        addMouseMotionListener(this);
    }
    
    @Override
    public void paint(Graphics g)
    {   int x[]={60,90,120};//Three x coordinates of triangle
        int y[]={160,120,160};//Three y coordinates of triangle
        
        /*Create Rectangle*/
        g.setColor(Color.RED);
        g.fillRect(20,40,50,30);//x1,y1,width,height
        
        /*Create Circle*/
        g.setColor(Color.BLUE);
        g.fillOval(100,40,50,50);//x,y coordinates of the upper leftmost corner of Oval , width,height
        
        /*Create Triangle*/
        g.setColor(Color.GREEN);
        g.fillPolygon(x,y,3);//array of x coordinates of vertices,array of y coordinates of vertices, no of sides
    }
    
    /* A utility function to calculate area of triangle formed by (x1, y1) (x2, y2) and (x3, y3) */
    double area(int x1, int y1, int x2, int y2,int x3, int y3)
    {   return Math.abs((x1*(y2-y3) + x2*(y3-y1)+x3*(y1-y2))/2.0);
    }
    
    /* A function to check whether point P(x, y) lies inside the triangle formed by A(x1, y1),B(x2, y2) and C(x3, y3) */
    boolean isInside(int x1, int y1, int x2,int y2, int x3, int y3, int x, int y)
    {   
       /* Calculate area of triangle ABC */
        double A = area (x1, y1, x2, y2, x3, y3);
      
       /* Calculate area of triangle PBC */ 
        double A1 = area (x, y, x2, y2, x3, y3);
      
       /* Calculate area of triangle PAC */ 
        double A2 = area (x1, y1, x, y, x3, y3);
      
       /* Calculate area of triangle PAB */  
        double A3 = area (x1, y1, x2, y2, x, y);
        
       /* Check if sum of A1, A2 and A3 is same as A */
        return (A == A1 + A2 + A3);
    }
    
    @Override
    public void mouseMoved(MouseEvent e)
    {   int x=e.getX();//get current x coordinates of cursor
        int y=e.getY();//get current y coordinates of cursor
        
        int a[]={60,90,120};//Three x coordinates of triangle
        int b[]={160,120,160};//Three y coordinates of triangle 
        
        /* Rectangle (20,40,50,30)ie if x between 20 and 20+50 AND y between 40 and 40+30
                                  ie if x between 20 and 70    AND y between 40 and 70  */
        /*Cursor inside Rectangle */
        if(x>=20 && x<=70 && y>=40 && y<=70)
            showStatus("Rectangle");
        
        /* Oval(100,40,50,50);//x,y coordinates of the upper leftmost corner of Oval , width,height 
                    ie Circle of centre(100+25,40+25) and radius (50/2)
                    ie Circle of centre(125,65)       and radius  25 */
        /* To be inside Circle,inside its Area => 
                    (x-h)^2 +(y-k)^2 <=radius^2    */
        else if (((x-125)*(x-125)+(y-65)*(y-65)) <= 625)
            showStatus("Circle");
            
        /*Within triangle*/      
        else if (isInside(a[0],b[0],a[1],b[1],a[2],b[2],x,y))
            showStatus ("Triangle");
                
        else
            showStatus ("No shapes selected");
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        ;//Empty declaration
    }
}