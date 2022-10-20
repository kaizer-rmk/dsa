#include<iostream>
#define SIZE 5

using namespace std;

int front,rear=-1;
int que[SIZE];

bool isFull(){
    if(rear>=SIZE-1)
        return true;
    return false;
}
bool isEmpty(){
    if(front==-1 && rear==-1)
        return true;
    return false;
}
void display(){
    for(int i=front;i<=rear;i++){
        printf("Queue[%d]: %d\n",i,que[i]);
    }
}
void enqueue(int value){
    if(!isFull()){
        rear++;
        que[rear]=value;
    }
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        que[rear]=value;
    }
    else 
         cout<<"Queue is Full!!!"<<endl;
    display();
}
void dequeue(){
    if(isEmpty())
        cout<<"Queue is Empty!!!";
    else if(front<=rear)
        front++;
    cout<<"Can't Perform Dequeue, As Front is Greater than Rear"<<endl;
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