/*Addition and Multiplication of 2 Complex Numbers */
#include<iostream>
using namespace std;
class complex{
    public:
        int i = 0;
        int r = 0;
        complex()
        {
            cout<<r<<" + "<<i<<" i "<<endl;
        }
        complex operator +(complex c1){
            complex c;
            c.r=r+c1.r;
            c.i=i+c1.i;
            return c;
        }
        complex operator *(complex c2){
            complex c;
            c.r=(r*c2.r)-(i*c2.i);
            c.i=(r*c2.i)+(c2.r*i);
            return c;
        }
        friend istream & operator >> (istream &in,complex &i);
        friend ostream & operator << (ostream & out,complex &d);
};
istream & operator>>(istream &in,complex &i)
{   
    cout<<"Enter Real Part : ";
    in>>i.r;
    cout<<"Enter Imaginary Part : ";
    in>>i.i;
    return in;
}
ostream & operator<<(ostream & out,complex &d)
{
    cout<<d.r <<" + "<<d.i<<" i ";
    return out;
}
int main()
{
    complex c,c1,c2,c3;
    cin>>c1;
    cin>>c2;
    c=c1+c2;
    c3=c1*c2;
    cout<<"Sum is :"<<c<<endl;
    cout<<"Product is : "<<c3;

    return 0;
}