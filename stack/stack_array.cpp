#include<iostream>
#define SIZE 5
using namespace std;

int tos=-1;
int n=5;
int arr[SIZE];

bool isFull(){
    if(tos>=n-1)
        return true;
    return false;
}
bool isEmpty(){
    if(tos<=-1)
        return true;
    return false;
}
void peek(){
    cout<<"\nThe Top stack is: "<<arr[tos]<<endl;
}
void push(int v){
if(isFull()){
    cout<<"Stack overflow!!!";
}
else{
    tos++;
    arr[tos]=v;
}
}
void pop(){
if(isEmpty()){
    cout<<"Stack underflow!!!";
}
else{
    tos--;
}
}
void display(){
    int i;
    for(i=tos;i>-1;i--){
        printf("\narr[%d]:\t%d",i,arr[i]);
    }
}

// ---------------------------------Main Function-------------------------------------
int main()
{
  int val,op;
  while(true){
    cout<<"\nPress 0. For EXIT";
    cout<<"\nPress 1. For PUSH";
    cout<<"\nPress 2. For POP";
    cout<<"\nPress 3. For Peek";
    cout<<"\nEnter Your choice:";
    cin>>op;
    switch(op){
    case 0:exit(0);
           break;
    case 1:cout<<"Enter the value:";
           cin>>val;
           push(val);
           display();
           break;
    case 2:pop();
           display();
           break;
    case 3:peek();
           break;
    default:cout<<"Wrong input!!!!!.....";
            break;
    }
  }
  return 0;
}