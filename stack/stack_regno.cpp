// Students of a Programming class arrive to submit assignments. 
// Their register numbers are stored in a LIFO list in the order in which 
// the assignments are submitted. Write a program using an array to display 
// the registered number of the ten students who submitted first. Register number of 
// the ten students who submitted first will be at the bottom of the LIFO list. 
// Hence pop out the required number of elements from the top so as to retrieve 
// and display the first 10 students. 

#include<iostream>
#include<string>

#define SIZE 15
using namespace std;

int tos=-1;
int n=15;
string arr[SIZE];

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
void push(string v){
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
        cout<<arr[i]<<endl;
    }
}
void first_ten(){
    for(int i=0;i<5;i++)
        pop();
    display();
}

// ---------------------------------Main Function-------------------------------------
int main()
{
  int op;
  string val;
  while(true){
    cout<<"\nPress 0. For EXIT";
    cout<<"\nPress 1. For PUSH";
    cout<<"\nPress 2. For POP";
    cout<<"\nPress 3. For Peek";
    cout<<"\nPress 4. For First 10 Student";
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
    case 4:first_ten();
           break;
    default:cout<<"Wrong input!!!!!.....";
            break;
    }
  }
  return 0;
}