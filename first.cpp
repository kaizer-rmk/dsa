#include<iostream>
#include<climits>
#include<cfloat>

#define PI 3.1415926

using namespace std;

int age {20};

int main(){
    int favNo;
    std::cout<<"Enter Your Favorite Number Between 1 and 100: ";
    cin>>favNo;
    cout<<"Your Favorite Number is: "<<favNo<<" :) "<<endl;
    cout<<"Char Minimum: "<<CHAR_MIN<<endl;
    cout<<"Intiger Maximum: "<<INT_MAX<<endl;

    return 0;
}