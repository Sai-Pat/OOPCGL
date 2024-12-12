#include<iostream>
#include<cstring>
using namespace std;
class Publication
{
    public:
        string title;
        float price;
};
class Book:public Publication{
    public:
    int pc;
    void get()
    {
        cout<<"Enter Name of Book : ";
        cin>>title;
        cout<<"Enter Price of Book : ";
        cin>>price;
        try{
        cout<<"Enter Page Count : ";
        cin>>pc;
        if(pc<=0)
        {
            throw 1;
        }
        }
        catch(int i){
            pc = 0;
            title= "0";
            price=0;
            display();
        }
    }
        void display()
    {
        cout<<"Name of Book : "<<title<<endl;
        cout<<"Price of Book : "<<price<<endl;
        cout<<"Page Count of Book : "<<pc<<endl;
    }
};
class Tape:public Publication{
    public:
    int time;
        void get()
    {
        cout<<"Enter Name of Tape : ";
        cin>>title;
        cout<<"Enter Price of Tape : ";
        cin>>price;
        try{
        cout<<"Enter Playing Minutes : ";
        cin>>time;
        if (time <= 0){
            throw 1;
        }
        }
        catch (int i)
        {
            cout<<" Invalid Playing time ";
            time =0;
            title = "0";
            price = 0;
            display();
        }
    }
        void display()
    {
        cout<<"Name of Tape : "<<title<<endl;
        cout<<"Price of Tape : "<<price<<endl;
        cout<<"Playing Time of Tape : "<<time<<endl;
    }

    
};
int main()
{   
    Book b;
    Tape t;
    int nb,nt;
    cout<<"Enter Number of Books : ";
    cin>>nb;
    for(int i=0;i<nb;i++){
        b.get();
    }
    cout<<"_____________________________________________"<<endl;
        for(int i=0;i<nb;i++){
        b.display();
    }
    
    cout<<"Enter Number of Tapes : ";
    cin>>nt;
        for(int i=0;i<nt;i++){
        t.get();
    }
    cout<<"_____________________________________________"<<endl;
        for(int i=0;i<nt;i++){
        t.display();
    }
    
    return 0;
}