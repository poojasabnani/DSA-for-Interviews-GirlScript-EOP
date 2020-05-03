# DSA DAY 3

## Topics Covered

* Stack
* Queue
* Recursion

## Theory

[Stack and Queue](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%203/stackandqueue.pptx?raw=true)

[Recursion](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%203/Recursion.pptx?raw=true)

### Other resources

#### Recursion Articles: 

[Geeksforgeeks 1](https://www.geeksforgeeks.org/recursion/)

[Geeksforgeeks 2](https://www.geeksforgeeks.org/tail-recursion/)

[FreeCodeCamp](https://www.freecodecamp.org/news/how-recursion-works-explained-with-flowcharts-and-a-video-de61f40cb7f9/)

#### Recursion Videos: 

[mycodeschool](https://www.youtube.com/playlist?list=PL2_aWCzGMAwLz3g66WrxFGSXvSsvyfzCO)

## Practise Problems

[Problem 1 from geeksforgeeks](https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/)

[Problem 2 from geeksforgeeks](https://www.geeksforgeeks.org/recursive-program-to-generate-power-set/)

[Problem 3 from geeksforgeeks](https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/) 

## Quiz

[Take the Quiz](https://forms.gle/z4NxFQKZKzvmVHvZ8)

## Code Snippets

Stack using Array

```c
#include<iostream>
using namespace std;
int s = 100;
class Stack {
    int* arr;
    int ptr;
public:
    Stack(){
        arr = new int[s];
        ptr = -1;
    }
    
    void push(int val){
        if(!isFull()){
            arr[++ptr] = val;
        }
        else {
            cout<<"Stack is full\n";
        }
    }
    void pop(){
        if(!isEmpty()){
            ptr--;
        }
        else{
            cout<<"Stack already empty!\n";
        }
    }
    int top(){
        if(!isEmpty()){ 
            return arr[ptr];
        }
        return -1; // if stack is empty we return -1
    }
    bool isFull(){
        if(ptr == s-1)
            return true;
        return false;
    }
    bool isEmpty(){
        if(ptr == -1){
            return true;
        }
        return false;
    }
    ~Stack(){
        delete [] arr;
    }

};
int main(){
    Stack st;
    st.push(5);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.push(53);
    st.push(41);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;

    return 0;
}
```
Stack using Linked List

```c
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
```
Check whether we have balanced brackets or not in the input , input only contains '(' and ')' for brackets. Other brackets (curly and square brackets) are not present in the input

```c
#include<bits/stdc++.h>
#define Stack stack<char>
// guys i have used STL to make code shorter 
// i will be teaching about STL Later in this course(very useful)
// for now assume there is a Stack class :))
using namespace std;
bool sol(string arr){
    if(arr.size()%2 !=0 ){ 
        // if odd length ..then can never be balanced
        return false;
    }
    Stack s;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == '('){
            s.push(arr[i]);
        }
        else if(arr[i] == ')') {
            if(!s.empty()){
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
   
    string in;
    cin>>in;
    //cout<<in<<endl;
    bool isbalanced = sol(in);
    if(isbalanced == false){
        cout<<"Not Balanced \n";
    }
    else {
        cout<<"Balanced \n";
    }

    return 0;
}
```

[Valid Paranthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

```c
#include<bits/stdc++.h>
#define Stack stack<int>
using namespace std;
bool sol(string s){
    int n = s.size();
    Stack openBracs,stars;
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '('){
            openBracs.push(i);
        }
        else if(ch == '*'){
            stars.push(i);
        }
        else {
            if(!openBracs.empty()){
                openBracs.pop();
            }
            else if(!stars.empty()){
                stars.pop();
            }
            else {
                return false;
            }
        }
    }
    while(!openBracs.empty() and !stars.empty()){
        if(openBracs.top()>stars.top())
            return false;
        else {
            openBracs.pop();
            stars.pop();
        }
    }
    
    return openBracs.empty(); // if we are able to nullify all the open brackets we return true
    // else false is returned... this handles both the situations
}
int main(){
    string in;
    cin>>in;
    bool isbalanced = sol(in);
    if(isbalanced == false){
        cout<<"Not Balanced\n";
    }
    else {
        cout<<"Balanced\n";
    }
    return 0;
}
```

Queue using Arrays

```c
#include<iostream>
using namespace std;
int s = 100; // size of underlying array
class Queue {
    int* arr;
    int frnt,rear;
public:
    Queue(){
        arr = new int[s];
        frnt = rear = -1;
    }
    void enqueue(int val){
        if(rear == -1){ // if this is the first element
            arr[++rear] = val;
            frnt = rear;
            return;
        }
        if(!isFull()){ 
            arr[++rear] = val;
        }
        else {
            cout<<"Queue is full\n";
        }
    }
    void dequeue(){
        if(!isEmpty()){
            frnt++;
            if(frnt == rear){
                arr[0] = arr[frnt];
                frnt = rear = 0;
            }
        }
        else
        {
            cout<<"Queue is empty\n";
        }
    }
    int front(){
        if(!isEmpty()){
            return arr[frnt];
        }
        return -1;
    }
    bool isEmpty(){
        if(frnt == -1 or frnt > rear){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(rear == s-1)
            return true;
        return false;
    }
    ~Queue(){
        delete [] arr;
    }
};
int main(){
    Queue q;
    q.enqueue(3);
    cout<<q.front()<<endl;
    q.enqueue(4);
    cout<<q.front()<<endl;
    q.enqueue(5);
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;

    return 0;
}
```

Queue using Linked List

```c
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

```

Perfect String Problem

```c
#include <bits/stdc++.h>
#define Queue queue<char> 
using namespace std;
// if you dont know about stl just assume we have a Queue class

// something like this...
// class Queue {
//     public:
//         void push(char ch); // insert char at the end
//         void pop(); // deletes char from front
//         char front(); // return the char at the front
// }

int findAns(string s, int changeallowed)
{
    int ans = 0;
    int na, nb;
    na = nb = 0;
    int changemade = 0;
    int currentans = 0;
    Queue q;
    int indx = 0;
    while (indx <= s.length()-1)
    {
        if (changemade < changeallowed or (na>=nb and s[indx] == 'a') or (nb>=na and s[indx] == 'b'))
        {
            if (s[indx] == 'a')
            {
                na++;
            }
            else
            {
                nb++;
            }
            q.push(s[indx]);
            changemade = min(na,nb);
            indx++;
            currentans++;
        }
        else {
            char whatIsDel = q.front();
            q.pop();
            if(whatIsDel == 'a')
                na--;
            else if(whatIsDel == 'b')
                nb--;
            
            changemade = min(na,nb);
            currentans--;
        }

        if (currentans > ans)
            ans = currentans;
    }

    return ans;
}
int main()
{
    int change;
    cin >> change;
    string s;
    cin >> s;

    cout << findAns(s, change);
    return 0;
}

```
Implementing Queue using two stacks

```c
#include<bits/stdc++.h>
#define Stack stack<int>
using namespace std;

/*  
    query can of 3 types 
    q == 1 than we have to push into the queue
    q == 2 than we have to pop an element
    q == 3 than we have to print the top element

*/

int main() {

    Stack ins;
    Stack del;
    int queries;
    cin>>queries;
    while(queries){
        int q;
        cin>>q;
        if(q == 1){
            int data;
            cin>>data;
            ins.push(data);
        }
        else if(q == 2){
            if(del.empty()){
                // if ins is also empty then queue is empty but 
                // that situation will never happen (input are in such a way this case never occur)

                // if the operation are not for sure valid you must handle that case when
                // both the stacks are empty then you can pop()
                while(!ins.empty()){
                    int temp = ins.top();
                    ins.pop();
                    del.push(temp);
                }
                del.pop();
            }
            else{
                del.pop();
            }
        }
        else if( q == 3){
            if(del.empty()){
                while(!ins.empty()){
                    int temp = ins.top();
                    ins.pop();
                    del.push(temp);
                }
                cout<<del.top()<<endl;

            }
            else{
                cout<<del.top()<<endl;
            }
        }
        queries--;
    }
    return 0;
}
```
