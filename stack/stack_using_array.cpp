#include <iostream>
using namespace std;
#define n 5
int stack[n];
int top = -1;

void push(){
    int data;
    cout<<"Enter your data: ";
    cin>>data;
    if(top==n-1){
        cout<<"stack is overflow";
        return;
    }
    else{
        top++;
        stack[top] = data;
        cout<<top;
        return;
    }
}
void pop(){
    if(top==-1){
        cout<<"stack is empty";
    }
    else{
        cout<<stack[top];
        top--;
    }
}
void display(){
    for(int i=n-1;i>=0;i--){
        cout<<stack[i]<<"";
    }
    return;
}
int main(){
    push();
    push();
    push();
    push();
    push();
    push();
    push();
    pop();
    display();
    return 0;
}