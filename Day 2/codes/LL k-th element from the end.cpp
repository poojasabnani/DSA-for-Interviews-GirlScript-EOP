/* write a program to find the k-th element from end in the given linkedlist

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
    // now the ll will be : 7-->6-->5-->4-->3-->2-->1-->END
    // find the 4nd element from the end
    int k = 4;
    node* ptr1 = head;
    node* ptr2 = head;
    for(int i=0; i<k; i++){
        ptr2= ptr2->next;
    }
    while(ptr2 != nullptr){
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
    }
    if(ptr1 != nullptr){
        cout<<k<<" th element from end is : " << ptr1->data<<endl;
    }

    return 0;
}