#include<iostream>
#define N 100
using namespace std;

void bubbleSort(int arr[],int n){
    bool swapped=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(swapped==false)
            break;
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
    bubbleSort(arr,n);

    cout<<endl<<"Sorted Array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}