#include<cstring>
#include<iostream>
using namespace std;
class Student{
    public:
    int rn;
    int c;
    char d;
    int dob;
    char bg;
    string name;
    static int count;
    //default Constructor
    Student()
    {
        name = "XYZ";
        rn=0;
        c=2;
        count ++;
    }

    //Copy Constructor
    Student(Student &s)
    {
        name=s.name;
        rn=s.rn;
        bg=s.bg;
        c=s.c;
        count ++;
    }
    // Destructor
    ~Student(){
        name= "XYZ";
        rn=0;
        bg = 'A';
        count --;
    }
    //Static Member Function
    static inline int getcount()
    {
        return count;
    }
    void get()
    {
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Roll No. ";
        cin>>rn;
        cout<<"Enter Class : ";
        cin>>c;
        cout<<"ENter Division :";
        cin>>d;
    }
    void display()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Roll No. "<<rn<<endl;
        cout<<"Class : "<<c<<endl;
        cout<<"Division : "<<d<<endl;
    }
    static void creatS(){
        Student *s = new Student();
        s->get();
        s->display();
        delete(s);
    }


};

int main()
{   Student S,S1(S);
    S.display();
    S1.display();
    S1.get();
    S1.display();

    return 0;
}