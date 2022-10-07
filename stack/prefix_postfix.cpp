#include<iostream>
#include<stack>

using namespace std;

string rev(string str){
    string reversed;
    int n = str.length();
    for(int i=n-1;i>=0;i--){
        reversed+=str[i];
    }
    return reversed;
}

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

//Infix to Postfix
string postfix(string exp){
    stack<char> post_stack;
    string post_exp;

    for(int i=0;i<exp.length();i++){
        char ch=exp[i];
        //For Operand
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
            post_exp+=ch;
        //For Open Bracket
        else if(ch=='(')
            post_stack.push(ch);
        //For Close Bracket
        else if(ch==')'){
            while(post_stack.top()!='('){
                post_exp+=post_stack.top();
                post_stack.pop();
            }
            post_stack.pop();
        }
        //For operand
        else{
            while(!post_stack.empty() && precedence(ch)<=precedence(post_stack.top())){
                post_exp+=post_stack.top();
                post_stack.pop();
            }
            post_stack.push(ch);
        }

    }
    while(!post_stack.empty()){
        post_exp+=post_stack.top();
        post_stack.pop();
    }
    return post_exp;
}

//Infix to Prefix
string prefix(string exp){
    //Reverse String
    string new_exp = rev(exp);
    //Replace ( with ) and ) with (
    for(int i=0;i<new_exp.length();i++){
        if(new_exp[i]=='(')
            new_exp[i]=')';
        else if(new_exp[i]==')')
            new_exp[i]='(';
    }
    //Find postfix
    string pre_exp=postfix(new_exp);
    //Again Reverse the result to get prefix
    pre_exp=rev(pre_exp);
    return pre_exp;

}



// ---------------------------------------Main Function-------------------------------------
int main(){
    string infix_exp="A+B*(C^D-E)^(f+g*h)-i";
    cout<<"------------------Infix-------------------"<<endl;
    cout<<"Infix Expression is: "<<infix_exp<<endl;
    cout<<"-----------------Prefix--------------------"<<endl;
    cout<<"PreFix Expression is: "<<prefix(infix_exp)<<endl;
    cout<<"-----------------Postfix--------------------"<<endl;
    cout<<"PostFix Expression is: "<<postfix(infix_exp)<<endl;

    return 0;
}