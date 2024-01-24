#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
class Linkedlist{
    Node* top;
    public:
    Linkedlist(){
       
        top = nullptr;
    }
    void push(int data);
    void pop();
    void display();
};
void Linkedlist::push(int data){
    Node* newNode = new Node(data);
    if(top==nullptr){
        top = newNode;
        return;
    }
    else{
        Node* temp =  newNode;
        temp->next = top;
        top = temp;
    }
}
void Linkedlist::pop(){
    if(top->next==nullptr){
        cout<<"stack is empty";
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
    return;

}
void Linkedlist::display(){
    Node* temp = top;
    while(temp!=nullptr){
        cout<<temp->data;
        temp = temp->next;
    }

}
int main(){
    Linkedlist stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.pop();
    stack.display();
    return 0;
}