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