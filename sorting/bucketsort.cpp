#include<iostream>
#include<vector>
#include<algorithm>
#define N 100
using namespace std;

void bucketSort(int arr[], int n){
    int k=5; //no. of bucket
    int max_val=arr[0];
    for(int i=1;i<n;i++)
        max_val=max(max_val,arr[i]);
    max_val++;
    
    vector<int> bkt[k];
    for(int i=0;i<n;i++){
        int bi=(k*arr[i])/max_val;
        bkt[bi].push_back(arr[i]);
    }
    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<bkt[i].size();j++)
            arr[index++]=bkt[i][j];
    }
}

int main(){
    int n;
    int arr[N];

    cout<<"Enter the No. of elements in array: ";
    cin>>n;
    cout<<"Enter elements of array: "<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    bucketSort(arr,n);

    cout<<endl<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}