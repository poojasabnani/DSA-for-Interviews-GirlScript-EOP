#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int val) : data(val),next(nullptr) { }
};
class Queue {
    node* frnt;
    node* rear;
public:
    Queue(): frnt(nullptr),rear(nullptr) { }

    void enqueue(int val){
        node* newnode = new node(val);
        if(rear == nullptr){
            frnt = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    void dequeue(){
        if(frnt != nullptr){
            node* temp = frnt;
            frnt = frnt->next;
            if(frnt == nullptr){
                rear = nullptr;
            }
            delete temp;
        }   
        else {
            cout<<"queue is already empty!\n";
        }
    }
    int front(){
        if(frnt != nullptr){
            return frnt->data;
        }
        else {
            return -1;
        }
    }
    bool isEmpty(){
        if(frnt == nullptr){
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.enqueue(43);
    cout<<q.front()<<endl;
    q.enqueue(32);
    if(!q.isEmpty())
        cout<<"Not empty\n";
    cout<<q.front()<<endl;
    q.enqueue(11);
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    return 0;
}