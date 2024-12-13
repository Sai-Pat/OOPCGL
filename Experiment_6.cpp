#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
class student{
    public:
    long t;
    string dob;
    string nam;
    

};
void display(student &s){
        cout<<"Name is : "<<s.nam<<endl;
        cout<<"Date of Birth is : "<<s.dob<<endl;
        cout<<"Telephone NUmber is : "<<s.t<<endl;
    }

int main(){
    string search;
    vector<student> s;
    int n;

    student s1;
    cout<<"Enter Number of Students : ";
    cin>>n;
    for(int i=0;i<n;i++){
        
        cout<<"Enter NAme :";
        cin>>s1.nam;
        cout<<"Enter Date of Birth :";
        cin>>s1.dob;
        cout<<"Enter Telephone Number :";
        cin>>s1.t;
        s.push_back(s1);        
    }
  int ch;
    cout << "\nChoose an operation:\n";
    cout << "1. Sort by Name\n";
    cout << "2. Sort by Phone Number\n";
    cout << "3. Sort by DOB\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> ch;
    switch (ch){
        case 1:
        sort(s.begin(),s.end(),[](student &a,student &b){
            return a.nam>b.nam;
        });
        cout<<"Sorted BY Name :";
        for(int i = 0;i<s.size();++i){
            display(s1);
        }
        break;
        case 2:
        sort(s.begin(),s.end(),[](student &a,student &b){
            return(a.t>b.t);
        });
        for(int i = 0;i<s.size();++i){
            display(s1);
        }
        break;
        case 3:
        sort(s.begin(),s.end(),[](student &a,student &b){
            return (a.dob>b.dob);
        });
        for(int i = 0;i<s.size();++i){
            display(s1);
        }
        break;
        case 4:
        cout<<"Enter Name to Be Searched : ";
        cin>>search;
        if(binary_search(s.begin(),s.end(),search)){
            cout<<"Record Found ! "<<endl;

        }
        else{
            cout<<"Record Not Found!!!"<<endl;
        }
    }

    
    return 0;
}
