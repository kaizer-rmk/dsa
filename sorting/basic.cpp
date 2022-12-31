#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int arr[5] {12,8,13,6,1};
    
    sort((arr),arr+5);
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;

    sort((arr),arr+5,greater<int>());
    for(int i:arr)
        cout<<i<<" ";
    cout<<endl;


    return 0;
}