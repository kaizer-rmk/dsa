#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
}*front=NULL,*rear=NULL;

typedef struct Node node;

bool isEmpty(){
    if(front==NULL)
        return true;
    return false;
}

void enqueue(int value){
    node * nn = new Node();
    nn->data=value;
    if(front==NULL && rear==NULL){
        front=rear=nn;
        nn->next=nn;
    }
    nn->next=front;
    rear->next=nn;
    rear=nn;
}
void dequeue(){
    if(isEmpty())
        cout<<"Queue is Empty!!!";
    else{
        node * temp;
        temp=front;
        if(front==temp->next){
            free(temp);
            front=rear=NULL;
        }
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void display(){
    node * temp=front;
    if(front==NULL){
        cout<<"Queue is Empty!!";
        return;
    }        
    while(temp->next!=front){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

int main(){
    int op,val;
    while(true){
        cout<<endl<<"Press 0. For Exit"<<endl;
        cout<<"Press 1. For Enqueue"<<endl;
        cout<<"Press 2. For Dequeue"<<endl;
        cout<<"Enter Your Choice:";
        cin>>op;
        switch(op){
            case 0: exit(0);
                    break;
            case 1: cout<<"Enter the value: ";
                    cin>>val;
                    enqueue(val);
                    display();
                    break;
            case 2: dequeue();
                    display();
                    break;
            default:cout<<"Wrong Choice!!"<<endl;
                    break;
        }
    }

    return 0;
}