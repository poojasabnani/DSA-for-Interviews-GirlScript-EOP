#include<iostream>
using namespace std; 
class node {
public:
    int data;
    node* next;
    node(int val) : data(val),next(nullptr) { }
};

class Stack {
    node* head;
public:
    Stack(){
        head = nullptr;
    }

    void push(int val){
        node* newnode  = new node(val);
        newnode->next = head;
        head = newnode;
    }
    void pop(){
        if(head != nullptr){
            node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            cout<<"stack is empty!"<<endl;
        }
    }
    int top(){
        if(head != nullptr){
            return head->data;
        }
        else {
            return -1;
        }  
    }
    bool isEmpty(){
        if(head == nullptr)
            return true;
        return false;
    }
};

int main(){
    Stack st;
    st.push(5);
    st.push(43);
    cout<<st.top()<<endl;
    st.pop();
    if(!st.isEmpty())
        cout<<"Not empty\n";
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}