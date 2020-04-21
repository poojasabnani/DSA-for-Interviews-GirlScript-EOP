// problem : find the mid element of given linkedlist

#include<iostream>
using namespace std;
class node {
public:
    int data; 
    node* next;
    node(int val) : data(val),next(nullptr) { }

};
void createLL(node* &head , int *arr,int n){
    for(int i=0; i<n; i++){
        node* temp = new node(arr[i]);
        temp->next = head ;
        head = temp;
    }
}
void display(node* head){
    while(head){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"END"<<endl;
}
int main(){
    node* head = nullptr;
    int arr[7] = {1,2,3,4,5,6,7};
    createLL(head,arr,7);
    display(head);

    // we will use two pointers,
    // one will move with 1x and other with 2x 
    // this ensures that if pointer with 2x speed reaches the end 
    // the pointer with 1x speed will be at middle only

    node* slow = head;
    node* fast = head;
    while(fast != nullptr and fast->next != nullptr){
        slow = slow->next;
        fast  = fast->next;
        fast = fast ->next;
        
    }
    cout<<"Middle is : "<<slow->data<<endl;
    
    return 0;
}