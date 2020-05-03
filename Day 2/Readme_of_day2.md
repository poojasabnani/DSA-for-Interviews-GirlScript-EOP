# DSA DAY 2

## Topics Covered

* Arrays
* Linked List

## Theory

[Arrays and Linked List](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%202/Array%20ppt%202.0.pptx?raw=true)

## Practise Problems

[Linked list problems on Hackerrank](https://www.hackerrank.com/domains/data-structures?filters%5Bsubdomains%5D%5B%5D=linked-lists)

#### Problem 2.

Given a linkedlist of characters data nodes. Can you find if the linkedlist is palindrome or not.

Example input: 

a->b->c->b->a->null

this Is a palindrome hence return true.

Conditions :

Don’t use extra space == > space complexity = O(1)

(you can ask for more question on slack I can provide more if you are done with these.

#### Problem 3.

Traverse the array diagonally and print the array

For eg :- If we have 2D array as

```c

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
```
Then print the following output 

```c

13
9 14
5 10 15
1 6  11 16 
2 7  12
3 8 
4

```

#### Problem 4

Given a 2d array print the sum of all the possible subarrays of the 2d array;

Explanation: 

You have to print the sum of all the 1 X 1 size array + sum of elements of all 1 X 2 array + …+ sum(1 X n) + 2 X 1 arrays + ….
2 X n arrays + …….+n X n arrays.

Try to optimize the solution as much as possible.

#### Problem 5

Given an array A. Rotate the array with some factor k to the left.

Explanation:

A : 1 2 3 4 5 6	and  	K = 2

Required  output for this testcase:

3 4 5 6 1 2

Try analyzing time complexity of your code.

(if done try to optimize the solution … there is an algo to do this in O(N) time and O(1) space.

## Code Snippets

[Implementation of Various types of Linked List](LinkedList.html)

Sorted Array Square

Given a sorted array print return the square of the array also in sorted order

Required time complexity : O(N)

For example

input: -11, -9, -6, 2, 5, 8, 10, 12
 
output: 4, 25, 36, 64, 81, 100, 121, 144

```c
#include<iostream>
using namespace std;


int main(){
    int arr[8] = {-11,-9,-6,2,5,8,10,12};
    int ans[8];
    int i=0,j = 8-1;
    int k = 8-1;
    while(i<=j){
        if(abs(arr[i])>abs(arr[j])){
            ans[k] = arr[i]*arr[i];
            k--;
            i++;
        }
        else {
            ans[k] = arr[j]*arr[j];
            k--;
            j--;
        }
    }
    cout<<endl;
    for(int i: ans){
        cout<< i << " ";
    }
    // the same two pointer approach can be used to reverse the array...
    return 0;
}
```
Shifting Zeroes to the end

Problem : given an input array A. Shift all the 0's to the end maintaining the relative order of nonzero elements.

input ::  8, 0, 9, 0, 1, 7, 2, 0, 31, 72 

output :: 8, 9, 1, 7, 2, 31, 72, 0, 0, 0

do this in O(N) time

space O(1)

```c
#include<iostream>
using namespace std;
int main(){
    int size = 10;// 8 9 1 7 
    int arr[size] = {8,0,9,0,1,7,2,0,31,72};
    // first of all we will start from index 0
    int indx =0;
    for(int i = 0; i<size; i++){
        if(arr[i] != 0){
            arr[indx] = arr[i];
            indx++;
        }
    }
     //  8 9 1 7 2 31 72  2,0,31,72

    // now all the nonzero elements are at the correct position
    // all we need to do is to add 0's in the end of arr;
    for(int i=indx; i<size; i++){
        arr[i] = 0;
    }
    
    // done
    // now printing the array

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```
Making Corresponding row and column elements 0

problem: given a matrix, if 0 is encoundered, make all the elements in corresponding row and column as 0. 

example :

Input Array

```c
1 2 0 4         
1 3 1 6     
9 4 5 1         
```
Output Array

```c
0 0 0 0
1 3 0 6
9 4 0 1
```
Required time : O(m*n)

```c
#include<iostream>
#include<cstring>
using namespace std; 
int main(){
    
    int m = 4;
    int n = 4;
    int arr[m][n] = {1,2,3,0,0,4,5,6,7,11,2,1,2,8,0,19};
    int rowFlag[m];
    int colFlag[n]; 
    // remember memset only works for (0 or -1) 
    // because it works on bits and is defined in cstring headerfile
    memset(rowFlag,-1,sizeof(rowFlag));
    memset(rowFlag,-1,sizeof(colFlag));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                rowFlag[i] = 0;
                colFlag[j] = 0;
            }
        }
    }
    // modifying the array
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rowFlag[i]==0 or colFlag[j] == 0){
                arr[i][j] = 0;
            }
        }
    }
    // printing the array
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
```
Reversing the linked list

Problem :  given the head of a linkedlist. Write a function to reverse the linkedlist.

```c
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
    p = q = nullptr; // p q r
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
```

Middle element of Linked List

Problem : find the mid element of given linkedlist

```c
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
```
Kth element from the end

Problem : Write a program to find the k-th element from end in the given linkedlist

```c
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
```







