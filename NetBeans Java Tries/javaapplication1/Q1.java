/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.applet.Applet;
import java.awt.event.MouseMotionListener;
import java.awt.*;
import java.awt.event.MouseEvent;

/**
 *
 * @author JEROME
 */
public class Q1 extends Applet implements MouseMotionListener{

    Label l;
    TextField t1,t2;
    @Override
    public void init()
    {
        l=new Label("Move over the shapes");
        add(l);
        addMouseMotionListener(this);
     
    }
    
    
    @Override
    public void paint(Graphics g)
    {
        int x[] = {60,90,120};
        int y[] = {160,120,160};
        
        g.setColor(Color.yellow);
        g.fillRect(20,40,50,30);
        
        g.setColor(Color.blue);
        g.fillOval(100,40,50,50);
        
        g.setColor(Color.green);
        g.fillPolygon(x,y,3);
        
       
    }
    
    
    /**
     *
     * @param x
     * @param y
     * @return 
     */
    public int area(int x, int y)
   {
       int a[] = {60,90,120};
        int b[] = {160,120,160};
        int c1,c2,c3;
        c1=y*(a[1]-a[0])-x*(b[1]-b[0])-b[0]*(a[1]-a[0])+a[0]*(b[1]-b[0]);
        c2=y*(a[2]-a[1])-x*(b[2]-b[1])-b[1]*(a[2]-a[1])+a[1]*(b[2]-b[1]);
        c3=(y-b[0])*(a[2]-a[0])-(x-a[0])*(b[2]-b[0]);
        if(c1>0 && c2>0 && c3<0) return 1;
        else 
            return 0;
   }
    @Override
    public void mouseMoved(MouseEvent e)
    {
        
        int x=e.getX(),y=e.getY();
        if(x>=20 && x<=70 && y>=40 && y<=70)
            showStatus("Rectangle");
        else
        if((y-65)*(y-65)+(x-125)*(x-125)<=625)
            showStatus("Circle");
        else
        if(area(x,y)==1)
            showStatus("Triangle");
        else
            showStatus("No shape selected");
    }

    @Override
    public void mouseDragged(MouseEvent e) {
    }
}
