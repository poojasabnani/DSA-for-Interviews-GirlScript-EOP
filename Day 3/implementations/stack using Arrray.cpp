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