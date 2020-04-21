#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int val) : data(val),next(nullptr) { }
    ~node() {
        if(next != nullptr)
            delete next;
    }
};
class List {
    node* head;
    node* findHelper(int val){
        node* temp = head;
        while(temp != nullptr){
            if(temp->data == val){
                break;
            }
            temp = temp->next;
        }
        return temp;
    }
public:
    List(){
        head = nullptr;
    }
    friend void reverse(List);
    void insert(int val){
        node* newnode = new node(val);
        newnode->next = head;
        head = newnode;
    }
    void remove(int val){
        node* findNode = findHelper(val);
        if(findNode == nullptr){ // this will handle both cases 1. if LL is empty and 2. node not present
            cout<<"Node not found\n";
            return;
        }
        if(findNode == head){ // special case
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* oneNodePrev = head;
        while(oneNodePrev->next != findNode){
            oneNodePrev = oneNodePrev->next;
        }
        // now we have access to node previous to the target
        // now modify the links
        oneNodePrev->next = findNode->next;
        delete findNode;
    }
    void display(){
        node* temp = head;
        if(isEmpty()){
            cout<<"list is empty!\n";
            return;
        }
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    bool isEmpty(){
        if(head == nullptr)
            return true;
        return false;
    }
    bool find(int val){
        node* findNode = findHelper(val);
        if(findNode != nullptr)
            return true;
        return false;
    }

};
void reverse(List l){
    //
}
void fun(){
    List l;
    l.insert(32);
    l.insert(321);
    l.insert(32);
    l.insert(321);
    l.insert(32);
    l.insert(321);
    l.display();
}

int main(){
    List mlist;
    fun();
    mlist.insert(45);
    mlist.insert(31);
    mlist.display();
    mlist.remove(421);
    mlist.display();
    mlist.remove(31);
    mlist.display();
    mlist.remove(45);
    mlist.display();
}