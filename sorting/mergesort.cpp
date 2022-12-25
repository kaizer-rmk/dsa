#include<iostream>
using namespace std;

void merge(int array[], int l, int m, int r) {
    int nl,nr;
    //Length of left and right sub array
    nl=m-l+1;
    nr=r-m;
    int larr[nl],rarr[nr];
    //insert values in left and right array
    for(int i=0;i<nl;i++)
        larr[i]=array[l+i];
    for(int j=0;j<nr;j++)
        rarr[j]=array[m+1+j];
    //Merge them to original array
    int i=0,j=0,k=l;
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
    while(i<nl){
        array[k]=larr[i];
        i++;
        k++;
    }
    while(j<nr){
        array[k]=rarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int begin,int end){
    if(begin>=end)
        return;
    int mid = begin+(end-begin)/2;
    mergesort(arr,begin,mid);
    mergesort(arr,mid+1,end);
    merge(arr,begin,mid,end);
}

void display(int *arr,int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<endl;
}

int main(){
    int n=8;
    int arr[] {85,24,63,45,17,31,96,50};
    cout<<"Intially Array: "<<endl;
    display(arr,n);
    mergesort(arr,0,n-1);
    cout<<"After Sorting: "<<endl;
    display(arr,n);
    return 0;
}