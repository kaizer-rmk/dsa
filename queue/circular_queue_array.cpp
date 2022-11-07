#include<iostream>
#define SIZE 5

using namespace std;
int front=-1,rear=-1;
int que[SIZE];

bool isEmpty(){
    if(front==-1 && rear==-1)
        return true;
    return false;
}
bool isFull(){
    if((front==0 && rear==SIZE-1)||(rear==(front-1)%(SIZE-1)))
        return true;
    return false;
}
void display(){
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("queue[%d]: %d \n",i,que[i]);
    }
    else
    {
        for (int i = front; i < SIZE; i++)
            printf("queue[%d]: %d \n",i, que[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("queue[%d]: %d \n",i, que[i]);
    }
    
}
void enqueue(int value){
    if(isFull()){
        cout<<"Queue is Full!!"<<endl;
        return;
    }
    if(front==-1 && rear==-1)
        front=rear=0;
    else if(rear==SIZE-1 && front!=0)
        rear=0;
    else
        rear++;
    que[rear]=value;
    display();
}
void dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty!!"<<endl;
        return;
    }
    else if(front==rear)
        front=rear=-1;
    else if(front=SIZE-1)
        front=0;
    else 
        front++;
    display();
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
                    break;
            case 2: dequeue();
                    break;
            default:cout<<"Wrong Choice!!"<<endl;
                    break;
        }
    }

    return 0;
}