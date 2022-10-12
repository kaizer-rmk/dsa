#include<iostream>
#define SIZE 30
using namespace std;

// ------------------------Stack Class----------------------------------
class stack{
    string stk[SIZE];
    int tos=-1;
    public:
        bool isFull(){
            if(tos>=SIZE-1)
                return true;
            return false;
        }
        bool isEmpty(){
            if(tos<=-1)
                return true;
            return false;
        }
        string top(){
            return stk[tos];
        }
        void push(string v){
            if(isFull()){
                cout<<"Stack overflow!!!";
            }
            else{
                tos++;
                stk[tos]=v;
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
        
};

// -----------------------------Forward & Backward---------------------------------
stack fwd,bwd;
string current {"http://dsa.com"};

void display(){
    cout<<"\nURL: "<<current<<endl;
}
void newpage(string page){
    while(!fwd.isEmpty()){
        fwd.pop();
    }
    bwd.push(current);
    current=page;
    display();
}
void goforward(){
    if(fwd.isEmpty())
        cout<<"No Page To Move Forward!!!"<<endl;
    else{
        bwd.push(current);
        current=fwd.top();
        fwd.pop();
    }
    display();
}
void gobackward(){
    if(bwd.isEmpty())
        cout<<"No Page To Move Back!!!"<<endl;
    else{
        fwd.push(current);
        current=bwd.top();
        bwd.pop();
    }
    display();
}


// -----------------------------------------Main Function----------------------------------------------------------
int main(){

    int op;
    string page;

    display();

    while(true){
        cout<<"\nPress 0. to Exit"<<endl;
        cout<<"press 1. to Add new page"<<endl;
        cout<<"Press 2. to Move forward"<<endl;
        cout<<"Press 3. to Move Backward"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>op;
        switch(op){
            case 0 :exit(0);
                    break;
            case 1 :cout<<"Enter Page: ";
                    cin>>page;
                    newpage(page);
                    break;
            case 2 :goforward();
                    break;
            case 3 :gobackward();
                    break;
            default:cout<<"Wrong Choice!!"<<endl;
                    break;
        }

    }

    return 0;
}



