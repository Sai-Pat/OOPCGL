#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class files{
    public:
    int rn;
    string name;
    void get(){
        cout<<"Enter NAme :" ;
        cin>>name;
        cout<<"Enter Roll No : ";
        cin>>rn;
        
    }
    void display(){
        cout<<"NAme : "<<name<<endl;
        cout<<"Roll No. : "<<rn<<endl;

    }
};
int main()
{   int n;
    cout<<"Enter Number of Students :";
    cin>>n;
    files F[n];
    for(int i=0;i<n;i++){
        ofstream f;
        f.open("Data.txt",ios::app);
        F[i].get();
        f.write((char*)&F[i],sizeof(F[i]));
        f.close();}
    cout<<"Displayin....................."<<endl;
    ifstream f;
    f.open("Data.txt",ios::in);
    for(int i=0;i<n;i++){
        
        
        f.read((char*)&F[i],sizeof(F[i]));
        F[i].display();
        f.close();

    }


}