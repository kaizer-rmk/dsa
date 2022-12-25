#include<iostream>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i];
    cout<<endl;    
}

void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            display(arr,n);
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        cout<<"After Pass"<<i<<": ";
        display(arr,n);
    }
}

int main(){
    int n=5;
    int arr1[] {1,2,3,4,5};
    int arr2[] {5,4,3,2,1};
    cout<<"\nPre-Sorted Array:"<<endl;
    insertionSort(arr1,n);
    cout<<"\nNot-Sorted Array:"<<endl;
    insertionSort(arr2,n);
    return 0;
}