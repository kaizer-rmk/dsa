#include<iostream>

using namespace std;

int lpartition(int arr[],int l,int h){
    int pivot=arr[h];

    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return(i+1);
}
void quickSort(int arr[],int l,int h){
    if(l<h){
        int p=lpartition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
int main(){

    int n=10;
    int arr[n] {900,200,1000,300,700,100,800,600,400,500};
    
    quickSort(arr,0,n-1);

    cout<<"Sorted Array: "<<endl;
    for(auto i: arr)
        cout<<i<<" ";

    return 0;
}