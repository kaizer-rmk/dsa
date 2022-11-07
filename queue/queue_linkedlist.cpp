#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
}*front=NULL,*rear=NULL;

typedef struct Node node;

bool isEmpty(){
    if(front==NULL && rear==NULL)
        return true;
    return false;
}

void enqueue(int value){
    node*nn=(node*)malloc(sizeof(node));
    nn->data=value;
    nn->next=NULL;
    if(front==NULL&&rear==NULL){
        front=rear=nn;
    }
    else{
        rear->next=nn;
        rear=nn;
    }
}
void dequeue(){
    if(front==NULL&&rear==NULL)
        cout<<"Queue is Empty!!!"<<endl;
    else{
        node * temp;
        temp=front;
        front=front->next;
        if(front==NULL)
            rear=NULL;
        free(temp);
    }
}
void display(){
    node * temp;
    for(temp=front;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
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