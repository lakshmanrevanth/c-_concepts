#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int data){
          this->data = data;
          this->next =NULL;
    }
};
class stack{
    node* top;
    public:
     stack():top(nullptr){};
     void push(int data);
     void pop();
     void printstack();
};
void stack::push(int data){
    node* newnode = new node(data);
    if(top==NULL){
        top = newnode;
        return;
    }
    newnode->next = top;
    top = newnode;
}

void stack::pop(){
    node* temp = top;
    top = temp->next;
    free(temp);
}
void stack::printstack(){
    node* temp = top;
    while(top!=NULL){
        cout<<top->data<<endl;
        top = top->next;
    }
}
int main(){
    stack stackobj;
    stackobj.push(10);
    stackobj.push(20);
    stackobj.push(30);
    stackobj.pop();
    stackobj.printstack();
    return 0;
}