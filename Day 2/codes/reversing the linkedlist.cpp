/*  problem :  given the head of a linkedlist. Write a function to 
                reverse the linkedlist.
*/


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
    // we have to use 3 pointers 
    // here is the beginnig of logic to reverse

    node* p;
    node* q;
    node* r;
    p = q = nullptr; // q p r
    r = head;
    while(r!= nullptr){
        q = r;
        r = r->next;
        q->next = p;
        p = q;
    }
    head = q;

    display(head);
    return 0;
}