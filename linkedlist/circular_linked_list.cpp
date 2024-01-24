#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int value;
    node* next;
    node(){
        value = 0;
        next = NULL;
    }
    node(int data){
        this->value = data;
        this->next = NULL;
    }
};
class Linkedlist{
    node* head;
    public:
    Linkedlist(){
        head = NULL;
    }
    void insertdata(int);
    void deletedata(int);
    void printlist();
};
void Linkedlist::insertdata(int data){
    node* newnode = new node(data);
    if(head==NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    if(temp->next == NULL){
       temp -> next = head;
    }
    temp->next = newnode;
}
void Linkedlist::printlist(){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}
void Linkedlist::deletedata(int no){
    node* temp1 = head;
    node* temp2 = NULL;
    int listno = 0;
    while(temp1!=NULL){
        temp1 = temp1->next;
        listno++;
    }
    if(no>listno){
        cout<<"index out of range...";
        return;
    }
    temp1=head;
    if(no==1){
      head = head->next;
      free(temp1);
      return;
    }
    else{
        while(no-- >1){
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
    }
}
int main(){
    Linkedlist list;
    list.insertdata(1);
    list.insertdata(20);
    list.insertdata(30);
    list.deletedata(1);
    list.printlist();
    return 0;
}