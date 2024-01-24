#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class Linkedlist{
    Node* head;
    public:
    Linkedlist(){
        head = NULL;
    }
    void insertdata(int);
    void printlist();
    void deletedata(int);
};
 void Linkedlist::insertdata(int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
};
void Linkedlist::printlist(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
};
void Linkedlist::deletedata(int no){
    Node* temp1=head;
    Node* temp2=NULL;
    int length = 0;
    while(temp1!=NULL){
        temp1=temp1->next;
        length++;
    }
    if(no>length){
        cout<<"index out of range";
        return;
    }
    temp1=head;
    if(no==1){
        head=head->next;
        free(temp1);
        return;
    }
    else{
        while(no-- >1){
            temp2=temp1;
            temp1=temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}
int main(){
    Linkedlist list;
    int listno;
    int i=0;
    cout<<"how many lists you have to enter: ";
    cin>>listno;
    while(listno>0){
        cout<<"please enter the data in the "<<i<<"node : ";
        cin>>i;
        list.insertdata(i);
        listno--;
    }
    list.printlist();
    list.deletedata(3);
    list.printlist();
    return 0;
}
