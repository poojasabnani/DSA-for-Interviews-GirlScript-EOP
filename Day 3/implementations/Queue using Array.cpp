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