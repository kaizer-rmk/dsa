#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

typedef struct Node node;

Node* create(int value){
    Node* nn=new Node;
    nn->data=value;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
}

void inorder(Node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* minimumNode(Node* curr){
    while(curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node* maximumNode(Node* curr){
    while(curr->right!=NULL){
        curr=curr->right;
    }
    return curr;
}

Node* insertion(Node* root,int value){
    if(root==NULL)
        return create(value);
    if(value<root->data)
        root->left=insertion(root->left,value);
    else
        root->right=insertion(root->right,value);
    return root;
}

Node* deletion(Node* root,int value){
    if(root==NULL) return root;
    
    if(value<root->data)
        root->left=deletion(root->left,value);
    else if(value>root->data)
        root->right=deletion(root->right,value);
    else{
        //If the node is with only one child or no child
        if(root->left==NULL){
            node * temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        //If the node have 2 child
        node* temp=minimumNode(root->right);
        root->data=temp->data;
        root->right=deletion(root->right,temp->data);
    }
    return root;
}

int main(){
    Node* root=NULL;
    int op,value;
    while(true){
        cout<<endl<<"Press 1: To Insert"<<endl;
        cout<<"Press 2: To Delete"<<endl;
        cout<<"Press 3: To Display"<<endl;
        cout<<"Press 4: To Get Max"<<endl;
        cout<<"Press 0: To Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>op;

        switch(op){
            case 0: exit(0);
                    break;
            case 1: cout<<"Enter The Value To Enter in BST: ";
                    cin>>value;
                    root=insertion(root,value);
                    break;
            case 2: cout<<"Enter the Value To Delete From BST: ";
                    cin>>value;
                    root=deletion(root,value);
                    break;
            case 3: cout<<"Display in Inorder"<<endl;
                    cout<<endl<<"Root: "<<root->data<<endl;
                    cout<<"----------------------------------"<<endl;
                    inorder(root);
                    cout<<endl<<"----------------------------------"<<endl;
                    break;
            case 4: cout<<endl<<"Maximum Value is: "<<maximumNode(root)->data<<endl;
                    break;
            default:cout<<"Wrong Choice!!"<<endl;
                    break;
        }
    }

    return 0;
}