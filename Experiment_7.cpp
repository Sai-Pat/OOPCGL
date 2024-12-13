#include<iostream>
#include<map>
#include<string>
#include<map>

using namespace std;

int main()
{
    string state;
    long pop;
    typedef map<string,long> mapType;
    mapType popmap;
    int n;
    cout<<"ENter No. of States : ";
    cin>>n;
    for(int i = 0; i<n;i++){
        cout<<"Enter State Name : ";
        cin>>state;
        cout<<"Enter Population of  "<<state<<" : ";
        cin>>pop;
        popmap.insert(pair<string,int>(state,pop));
    }
    mapType::iterator it;
    for(it=popmap.begin();it!=popmap.end();it++)
    {
        cout<<"State : "<<it->first<<endl;
        cout<<"Population : "<<it->second<<endl;
        
    }
    return 0;
}