#include<iostream>
#include<vector>
using namespace std;

void upheapifyRecursive(vector<int> &heap,int indx){
    if(indx == 0)
        return;
    
    int parentIndx = (indx-1)/2;
    if(heap[parentIndx]<heap[indx]){
        swap(heap[parentIndx],heap[indx]);
        upheapifyRecursive(heap,parentIndx);
    }
    else 
        return;
}
void insert(vector<int> &heap,int key){
    heap.push_back(key);
    upheapifyRecursive(heap,heap.size()-1);
}
void display(vector<int> heap){
    for(auto i: heap)
        cout<<i<<" ";
    cout<<endl;
}
int main(){

    vector<int> heap;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x; 
        cin>>x;
        insert(heap,x);
    }
    display(heap);
    return 0;
}