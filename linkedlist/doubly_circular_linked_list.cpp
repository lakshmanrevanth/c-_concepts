// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// class node{
//     public:
//     node* prev;
//     int data;
//     node* next;
//     node(){
//         data = 0;
//         prev = NULL;
//         next = NULL;
//     }
//     node(int data){
//         this->data = data;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };
// class Linkedlist{
//     node* head;
//     public:
//     Linkedlist(){
//         head = NULL;
//     }
//     void insertdata(int data){
//         node* newnode = new node(data);
//         if(head == NULL){
//             head = newnode;
//             return;
//         }
//         node* ftemp = head;
//         node* ptemp = head;
//         while(ftemp->next!=NULL){
//             ftemp = ftemp->next;
//             ptemp = ftemp;
//         }
//         ftemp->next = newnode;
//         ftemp = ftemp->next;
//         ftemp->prev = ptemp;
//         if(ftemp->next==NULL){
//             ftemp->next=head;
//         }
//     }
//     void deletedata(int no){
//         node* temp1=head;
//     node* temp2=NULL;
//     int length = 0;
//     while(temp1!=NULL){
//         temp1=temp1->next;
//         length++;
//     }
//     if(no>length){
//         cout<<"index out of range";
//         return;
//     }
//     temp1=head;
//     if(no==1){
//         head=head->next;
//         free(temp1);
//         return;
//     }
//     else{
//         while(no-- >1){
//             temp2=temp1;
//             temp1=temp1->next;
//         }
//         temp2->next = temp1->next;
//         free(temp1);
//         temp1=temp2->next;
//         temp1->prev=temp2;
//     }
//     }
//     void printlist(){
//         node* temp = head;
//         while(temp->next!=head){
//             cout<<temp->data;
//             temp = temp->next;
//         }
//     }
// };
// int main(){
//     Linkedlist list;
//     list.insertdata(1);
//     list.insertdata(2);
//     list.insertdata(3);
//     list.deletedata(1);
//     list.printlist();
//     return 0;
// }
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};
class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insertData(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* last = head->prev;
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
        }
    }
    void deleteData(int position) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        int count = 1;
        do {
            if (position == count) {
                if (current == head && current->next == head) {
                    delete current;
                    head = nullptr;
                } else {
                    Node* prevNode = current->prev;
                    Node* nextNode = current->next;
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    if (current == head) {
                        head = nextNode;
                    }
                    delete current;
                }
                cout << "Deleted node at position " << position << endl;
                return;
            }
            current = current->next;
            count++;
        } while (current != head);
        cout << "Position " << position << " not found in the list!" << endl;
    }
    void printList() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    ~LinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        Node* next = nullptr;
        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != head);
    }
};
int main() {
    LinkedList list;
    list.insertData(1);
    list.insertData(2);
    list.insertData(3);
    list.deleteData(1);
    list.printList();
    return 0;
}