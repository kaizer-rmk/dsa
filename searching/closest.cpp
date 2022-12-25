#include<iostream>

using namespace std;

int find_closest(int arr[],int val,int n){
    int diff=9999999;
    int temp;
    for(int i=0;i<n;i++){
        if(arr[i]==val)
            return i;
        else{
            float distance=abs(val-arr[i]);
            if(distance<diff){
                diff=distance;
                temp=i;
            } 
        }
    }
    return temp;
}

int main(){
    int n=5;
    int arr[n],val;
    cout<<"Enter the 5 Elements: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the value to find: ";
    cin>>val;
    int res=find_closest(arr,val,n);

    cout<<endl<<"Nearest Value is: "<<arr[res];

    return 0;
}