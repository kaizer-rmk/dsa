#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
}*head=NULL;

typedef struct Node node;

void display(){
    node* temp;
    if(head==NULL)
        cout<<"Linked List is Empty!!"<<endl;
    for(temp=head;temp!=NULL;temp=temp->next){
        cout<<temp->data<<endl;
    }
}

void insert_b(int value){
    node * nn = (node*)malloc(sizeof(node));
    nn->data=value;
    nn->next=head;
    head=nn;
}
void insert_e(int value){
    if(head==NULL){
        insert_b(value);
    }
    else{
        node * nn = (node*)malloc(sizeof(node));
        node * temp;
        for(temp=head;temp->next!=NULL;temp=temp->next);
        temp->next=nn;
        nn->data=value;
        nn->next=NULL;
    }
}
void insert_s(int value,int pos){
    if(head==NULL)
        cout<<"No Data Available In Linked List Try Entring Position as 1"<<endl;
    else{
        int count=1;
        if(pos==count)
            insert_b(value);
        else{
            node * temp;
            node * nn = (node*)malloc(sizeof(node));
            nn->data=value;
            for(temp=head;temp->next!=NULL;temp=temp->next){
                count++;
                if(pos==count)
                    break;
            }
            if(pos>count+1)
                cout<<"Invalid Position!!"<<endl;
            else if(pos==count+1){
                insert_e(value);
            }
            else{
                nn->next=temp->next;
                temp->next=nn;
            }
        }
    }
}

void insert(int value){
    int op,pos;
    cout<<"Press 1. To Insert At Beginning"<<endl;
    cout<<"Press 2. To Insert At End"<<endl;
    cout<<"Press 3. To Insert at Specific Position"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>op;
    switch(op){
        case 1: insert_b(value);
                break;
        case 2: insert_e(value);
                break;
        case 3: cout<<"Enter Position you want to enter: ";
                cin>>pos;
                insert_s(value,pos);
                break;
        default:cout<<"Wrong Choice!!!";
                break;
    }
}
void del_b(){
    if(head==NULL)
        cout<<"Can't Delete, Linked List is Empty!!";
    node* temp;
    temp=head;
    head=head->next;
    free(temp);
}
void del_e(){
    if(head==NULL)
        cout<<"Can't Delete, Linked List is Empty!!";
    node* temp;
    for(temp=head;temp->next->next!=NULL;temp=temp->next);
    free(temp->next);
    temp->next=NULL;
}
void del_s(int pos){
    if(head==NULL)
        cout<<"Can't Delete, Linked List is Empty!!";
    else{
        int count=1;
        if(pos==count)
        del_b();
        else{
            node* temp;
            for(temp=head;temp->next!=NULL;temp=temp->next){
                count++;
                if(pos==count)
                    break;
            }
            if(pos>count+1)
                cout<<"Invalid Position!!"<<endl;
            else if(pos==count+1)
                del_e();
            else{
                node* curr=temp->next;
                temp->next=curr->next;
                free(curr);
            }
        }
    }
}
void delete_all(){
    node * temp=head;
    node * curr=NULL;
    while(temp!=NULL){
        curr=temp->next;
        free(temp);
        temp=curr;
    }
    head=NULL;
}
void del(){
    int op,pos;
    cout<<"Press 1. To Delete At Beginning"<<endl;
    cout<<"Press 2. To Delete At End"<<endl;
    cout<<"Press 3. To Delete at Specific Position"<<endl;
    cout<<"Press 4. To Delete all"<<endl;
    cout<<"Enter Your Choice: ";
    cin>>op;
    switch(op){
        case 1: del_b();
                break;
        case 2: del_e();
                break;
        case 3: cout<<"Enter Position you want to enter: ";
                cin>>pos;
                del_s(pos);
                break;
        case 4: delete_all();
                break;
        default:cout<<"Wrong Choice!!!";
                break;
    }
}
void length(){
    int count=0;
    for(node* temp=head;temp!=NULL;temp=temp->next)
        count++;
    cout<<"The Length of LinkedList is: "<<count<<endl;
}
// --------------------------------------------Main Function---------------------------------------------
int main(){
    int op,value;
    while(true){
        cout<<"Press 0. To Exit"<<endl;
        cout<<"Press 1. To Insert"<<endl;
        cout<<"Press 2. To Delete"<<endl;
        cout<<"Press 3. To Find Length"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>op;
        switch(op){
            case 0: exit(0);
                    break;
            case 1: cout<<"Enter the Value: ";
                    cin>>value;
                    insert(value);
                    display();
                    break;
            case 2: del();
                    display();
                    break;
            case 3: length();
                    break;
            default:cout<<"Wrong Choice!!!"<<endl;
                    break;
        }
    }

    return 0;
}
