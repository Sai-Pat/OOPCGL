#include<iostream>
#include<vector>
#include<algorithm>

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
        void display()const
        {
            cout<<"Name is : "<<name;
            cout<<"Roll no is : "<<roll;
        }
        static bool compare(const PR& a ,const PR& b)
        {
            return a.name <b.name;
        }
};
int main()
{

    int n,x,y;
    cout<<"Enter Numbr of Students : ";
    cin>>n;
    cout<<"Wnna continue ? ( 0 or 1 ): ";
    cin>>y;
    vector<PR> v(n);
    do{
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
            sort(names.begin(),names.end());
            string key;
            cout<<"Enter Name to Be searched : ";
            cin>>key;
            if(binary_search(names.begin(),names.end(),key)){

                cout<<"REcord Found !"<<endl;
            }
            else{
                cout<<"not Found!";
            }


            break;
        }
        case 4:
        {
            for(int i=0;i<n;i++)
            {
                v[i].display();
                cout<<endl;
            }
            break;
        }
    }

    }
    while(y==1);

    return 0;
}
