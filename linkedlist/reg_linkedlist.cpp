// Consider a linked list with a header node, where each node contains the 
// student name, register number and the average of all subjects. The header 
// node contains a sentinel registration number to be -99. To perform the 
// following operations, identify an appropriate linked list which is most suitable.
// a) Write a node structure definition for the linked list.
// b) Write a C function to display the records of the students with average more 
// than 90 marks.

#include<iostream>
using namespace std;

class Node{
    string sname;
    string reg_no;
    int avg;
    Node *next;
    public:
        Node *head = NULL;
        void sentinel(){
            Node *nn = new Node();
            nn->sname="xyz";
            nn->reg_no="-99";
            nn->avg=0;
            nn->next=NULL;
            head=nn;
        }
        void insert(string s,string r,int avg){
            Node *nn = new Node();
            nn->sname=s;
            nn->reg_no=r;
            nn->avg=avg;
            
            Node *temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        }
        void display(){
            Node *temp;
            for(temp=head;temp!=NULL;temp=temp->next){
                if(temp->avg>90 && temp->reg_no!="-99"){
                    cout<<"-------------------------------------------"<<endl;
                    cout<<"Regestration No. : "<<temp->reg_no<<endl;
                    cout<<"Student Name : "<<temp->sname<<endl;
                    cout<<"Average Marks : "<<temp->avg<<endl;
                    cout<<"-------------------------------------------"<<endl;
                }
            }
        }
};

int main(){
    Node std;
    std.sentinel();
    std.insert("Mukesh Kumar","22MCA0043",400);
    std.insert("Mukul Anand","22MCA0500",420);
    std.insert("Kaizer","22MCA0643",89);
    std.insert("Rahul Kumar","22MCA0440",360);
    std.display();

    return 0;
}