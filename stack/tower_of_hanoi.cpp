#include<iostream>

using namespace std;

void toh(int n,char from,char to,char aux){
    if(n==0)
        return;
    toh(n-1,from,aux,to);
    cout<<"Move "<<n<<" from "<<from<<" to "<<to<<endl;
    toh(n-1,aux,to,from);

}

int main(){

    int n;
    char x='A',y='C',z='B';
    cout<<"Enter the levels: ";
    cin>>n;
    toh(n,x,y,z);

    return 0;
}