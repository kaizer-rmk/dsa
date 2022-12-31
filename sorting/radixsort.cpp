#include<iostream>

using namespace std;

int getmax(int arr[],int n){
    int m=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>m)
            m=arr[i];
    return m;
}

void countSort(int arr[],int n,int x){
    int output[n];
    int count[10] {0};
    
    for(int i=0;i<n;i++)
        count[(arr[i]/x)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/x)%10]-1]=arr[i];
        count[(arr[i]/x)%10]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void radixSort(int arr[],int n){
    int m = getmax(arr,n);
    for(int i=1;m/i>0;i*=10)
        countSort(arr,n,i);
}

int main(){
    int n=8;
    int arr[] {865,54,671,132,1,966,356,8};

    radixSort(arr,n);

    cout<<"Sorted Array: "<<endl;
    for(auto i:arr)
        cout<<i<<" ";

    return 0;
}