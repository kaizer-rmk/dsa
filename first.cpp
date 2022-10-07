#include<iostream>
#include<climits>
#include<cfloat>

#define PI 3.1415926

using namespace std;

int age {10};

int main(){
    int favNo;
    std::cout<<"Enter Your Favorite Number Between 1 and 100: ";
    cin>>favNo;
    cout<<"Your Favorite Number is: "<<favNo<<" :) "<<endl;
    cout<<"Char Minimum: "<<CHAR_MIN<<endl;
    cout<<"Intiger Maximum: "<<INT_MAX<<endl;

    cout<<"______________________________"<<endl;

    int score{10};
    int* score_ptr=&score;
    cout<<"Value: "<<score<<endl;
    cout<<"Pointer Value: "<<score_ptr<<endl;
    cout<<*score_ptr;

    return 0;
}