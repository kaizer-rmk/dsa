#include<iostream>
#define N 100
using namespace std;

void selectionSort(int arr[],int n){
    int min_idx;
    for(int i=0;i<n-1;i++){
        min_idx=i;
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx=j;
        if(i!=min_idx){
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
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
    selectionSort(arr,n);

    cout<<endl<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}