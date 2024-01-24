#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node* prev;
    int value;
    node* next;
    node(){
        prev = NULL;
        value = 0;
        next = NULL;
    }
    node(int data){
        this->value = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
class Linkedlist{
    node* head;
    public:
    Linkedlist(){
        head=NULL;
    }
    void insertdata(int);
    void deletedata(int);
    void printlist();
};
void Linkedlist::insertdata(int data){
    node* newnode = new node(data);
    if(head == NULL){
        head=newnode;
        return;
    }
    node* ftemp = head;
    node* ptemp= head;
    while(ftemp->next!=NULL){
        ftemp = ftemp->next;
        ptemp = ftemp;
    }
    ftemp->next = newnode;
    ftemp = ftemp->next;
    ftemp->prev = ptemp;
}
void Linkedlist::printlist(){ 
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->value;
        temp=temp->next;
    }  
}
void Linkedlist::deletedata(int no){
    node* temp1=head;
    node* temp2=NULL;
    int listno = 0;
    while(temp1->next!=NULL){
        temp1=temp1->next;
        listno++;
    }
    if(no>listno){
        cout<<"index out of range"<<endl;
        return;
    }
    temp1 = head;
    if(no==1){
        head=head->next;
        free(temp1);
        return;
    }
    else{
        while(no-- >1){
             temp2= temp1;
             temp1=temp1->next;
        }
        temp2->next = temp1->next;
        free(temp1);
        temp1=temp2->next;
        temp1->prev = temp2;
    }
}
int main(){
    Linkedlist list;
    list.insertdata(1);
    list.insertdata(2);
    list.insertdata(3);
    list.deletedata(2);
    list.printlist();
    return 0;
}