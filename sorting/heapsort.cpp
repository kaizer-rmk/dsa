#include<iostream>
#define N 100
using namespace std;

void maxHeapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    for(int i=(n-2)/2;i>=0;i--)
        maxHeapify(arr,n,i);
    for(int i=n-1;i>=1;i--){
        swap(arr[0],arr[i]);
        maxHeapify(arr,i,0);
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
        
    heapSort(arr,n);

    cout<<endl<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}