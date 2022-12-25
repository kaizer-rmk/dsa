// In a circular singly linked list, it is said that having a pointer to the last node in a circular 
// linked list is better than having a pointer to the first node, with respect to insertion. Give 
// the necessary code snippet to perform front and back insertion in both the cases. 

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
}*ptr=NULL;

typedef struct Node node;

void display(){
    node* temp;
    if(ptr==NULL){
        cout<<"Linked List is Empty!!"<<endl;
        return;
    }
    temp=ptr->next;
    do{
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=ptr->next);
}

void insertAtStart(int value){
    node * nn = (node*)malloc(sizeof(node));
    nn->data=value;
    if(ptr==NULL){
        ptr=nn;
        nn->next=ptr;
    }
    nn->next=ptr->next;
    ptr->next=nn;
}
void insertAtEnd(int value){
    node * nn = (node*)malloc(sizeof(node));
    nn->data=value;
    if(ptr==NULL){
        ptr=nn;
        nn->next=ptr;
    }
    nn->next=ptr->next;
    ptr->next=nn;
    ptr=nn;

}
void insertAtMiddle(int value,int pos){
    if(ptr==NULL)
        cout<<"No Data Available In Linked List"<<endl;
    else{
        int count=1;
        if(pos==count)
            insertAtStart(value);
        else{
            node * temp;
            node * nn = (node*)malloc(sizeof(node));
            nn->data=value;
            for(temp=ptr->next;temp->next!=ptr;temp=temp->next){
                count++;
                if(pos==count)
                    break;
            }
            if(pos>count+1)
                cout<<"Invalid Position!!"<<endl;
            else if(pos==count+1){
                insertAtEnd(value);
            }
            else{
                nn->next=temp->next;
                temp->next=nn;
            }
        }
    }
}

int main(){
    int op,value,pos;
    while(true){
        cout<<"Enter the Value: ";
        cin>>value;
        cout<<"Press 0. To Exit"<<endl;
        cout<<"Press 1. To Insert at Start"<<endl;
        cout<<"Press 2. To Insert at End"<<endl;
        cout<<"Press 3. To Insert at Middle"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>op;
        switch(op){
            case 0: exit(0);
                    break;
            case 1: insertAtStart(value);
                    display();
                    break;
            case 2: insertAtEnd(value);
                    display();
                    break;
            case 3: cout<<"Enter Middle Position: ";
                    cin>>pos;
                    insertAtMiddle(value,pos);
                    display();
                    break;
            default:cout<<"Wrong Choice!!!"<<endl;
                    break;
        }
    }

    return 0;
}