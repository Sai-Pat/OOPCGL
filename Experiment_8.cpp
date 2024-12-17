#include<iostream>
#include<graphics.h>
#include<stdlib>
#include<maths>

        void dda(int x1,int x2,int y1,int y2)
        {
            float x,y,dx,dy,step,xinc,yinc;
            int i;
            dx=abs(x2-x1);
            dy=abs(y2-y1);
            if(dx>dy){
                step=dx;
            }
            else{
                step=dy;
            }
            xinc=(x2-x1)/(float)step;
            yinc=(y2-y1)/(float)step;
            x=x1+0.5;
            y=y1+0.5;
            for(int i=0;i<=step;i++)
            {
                putpixel(x,y,12);
                x=x+xinc;
                y=y+yinc;
            }
            putpixel(x,y,12);

        }

        void bc(float x1, float y1,int r)
        {
            float Pk,x,y;
            x=3-(2*r);
            x=0;
            y=r;
            while(x<=y)
            {
                plot(x,y,x1,y1);
                if (Pk<0){
                    x=x+1;
                    x=Pk+(4*x)+6;
                }
                else{
                    x=x+1;
                    y=y-1;
                    x=Pk+(4*(x-y))+10;
                }
            }
        }
        void plot(int x,int y,int x1, int y1)
        {
            putpixel(x+x1,y+y1,7);
            putpixel(y+x1,x+y1,7);
            putpixel(-x+x1,y+y1,7);
            putpixel(y+x1,-x+y1,7);
            putpixel(x+x1,-y+y1,7);
            putpixel(-y+x1,x+y1,7);
            putpixel(-x+x1,-y+y1,7);
            putpixel(-y+x1,-x+y1,7);
            delay(500);
        }

int main()
{
    int gd=DETECT, gm;
    int x,y,r1,r2,x1,y1,x2,y2,x3,y3;
    cout<<"Enter Center :";
    cin>>x>>y;
    cout<<"Enter Outer Radius : ";
    cin>>r1;
    cout<<"Enter Inner Radius : ";
    cin>>r2;
    initgraph(&gd,&gm,NULL);
    bc(x,y,r1);
    bc(x,y,r2);
    int l;
    l=sqrt((r1*r1)-(r2*r2));
    x1=x;
    y1=y-r1;
    x2=x-l;
    y2=y+r2;
    x3=x+l;
    y3=y+r2;
    dda(x1,y1,x2,y2);
    dda(x1,y1,x3,y3);
    dda(x2,y2,x3,y3);
    return 0;
}