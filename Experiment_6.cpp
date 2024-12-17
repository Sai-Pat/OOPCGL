#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
class PR{
    public:
        string name;
        int roll;
        void get()
        {
            cout<<"Enter Name : ";
            cin>>name;
            cout<<"ENter Roll no : ";
            cin>>roll;
        }
        void display()
        {
            cout<<"Name is : "<<name;
            cout<<"Roll no is : "<<roll;
        }
        static bool compare(PR &a , PR &b)
        {
            return a.name>b.name;
        }
};
int main()
{
    int n,x;
    cout<<"Enter Numbr of Students : ";
    cin>>n;
    vector<PR> v(n);
    cout<<"What to DO? : "<<endl;
    cout<<"1.insert data"<<endl;
    cout<<"2.sort data"<<endl;
    cout<<"3.search "<<endl;
    cout<<"4.display "<<endl;
    cin>>x;
    switch(x){
        case 1:
        {
            for(int i=0;i<n;i++)
            {
                v[i].get();
            }
            break;
        }
        case 2:
        {
            sort(v.begin(),v.end(),PR::compare);
            cout<<"Sorted!!!"<<endl;
            break;

        }
        case 3:
        {
            vector <string> names;
            for(int i=0;i<n;i++)
            {
                names.push_back(v[i].name);
            }
            sort(v.begin(),v.end(),PR::compare);
            string key;
            cout<<"Enter Name to Be searched : ";
            cin>>key;
            if(binary_search(v.begin(),v.end(),key)){
                cout<<"REcord Found !"<<endl;
            }
            else{
                cout<<"not Found!";
            }


            break;
        }

    }

    return 0;
}
