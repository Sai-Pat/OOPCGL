#include<iostream>
#include<algorithm>
using namespace std;
template<class T>
T Selection_Sort(T a[],int n){
    cout<<"Enter Number of Elements : ";
    cin>>n;
    int t;
for(int i=0;i<n;i++){
    cout<<"Enter Element : ";
    cin>>a[i];
}
for(int i =0;i<n;i++){
    t=i;
    for(int j = i+1;j<n;j++){
        if(a[j]<a[t]){
            t=j;
        }
    }
    swap(a[i],a[t]);
}
for(int i =0;i<n;i++){
    cout<<a[i]<<" ";
}
}
int main()
{   
    int ch;
    cout<<"What to do : ?"<<endl;
    cout<<"1.Integer Sorting"<<endl;
    cout<<"2.FLoat Sorting "<<endl;
    cout<<"3.Character Sorting "<<endl;
    cin>>ch;
    switch(ch){
        case 1:
        {   int n;
            int *a=new int[n];
            Selection_Sort(a,n);
            delete[]a;
            break;
        }
        case 2:
        {
            int n;
            float *a=new float[n];
            Selection_Sort(a,n);
            delete[]a;
            break;

        }
        case 3:
        {
            int n;
            char * a=new char [n];
            Selection_Sort(a,n);
            delete[]a;
            break;
        }
        default:
        cout<<"Invalid Choice .."<<endl;;
    }
    return 0;
}