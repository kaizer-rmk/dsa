#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
}*head=NULL;

typedef struct Node node;

void display(){
    node* temp;
    for(temp=head;temp!=NULL;temp=temp->next)
        cout<<temp->data<<endl;
}
bool isEmpty(){
    if(head==NULL)
        return true;
    return false;
}
void push(int value){
    node* nn=new node();
    nn->data=value;
    nn->next=head;
    head=nn;
}
void pop(){
    if(isEmpty())
        cout<<"Stack is Empty!!!"<<endl;
    node* temp;
    temp=head;
    head=head->next;
    free(temp);
}
void peek(){
    cout<<"Peek Value is: "<<head->data<<endl;
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
