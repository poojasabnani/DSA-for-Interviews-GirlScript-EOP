# DSA DAY 5

## Topics Covered

Heaps

## Theory

[Heaps](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%205/Heap.pptx?raw=true)

## Quiz

[Take the Quiz](https://forms.gle/m1a7Le8DYXy8Sxbi8)

## Code Snippets

Heap Implementation

```c
#include<iostream>
#include<vector>
using namespace std;


void downHeapify(vector<int> &heap , int indx){
    int leftIndx = 2*indx + 1;
    int rightIndx = 2*indx + 2;
    if(leftIndx >=heap.size() and rightIndx >= heap.size()){
        return;
    }
    int largestIndx = indx;
    if(leftIndx < heap.size() and heap[leftIndx]>heap[largestIndx]){
        largestIndx = leftIndx;
    }
    if(rightIndx < heap.size() and heap[rightIndx]>heap[largestIndx]){
        largestIndx = rightIndx;
    }
    if(largestIndx == indx)
        return;
    swap(heap[largestIndx],heap[indx]);
    downHeapify(heap,largestIndx);

}


void deletePeak(vector<int> &heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}
/* optional

void upheapifyIterative(vector<int> &heap,int indx){
    if(indx == 0){
        return;
    }
    else {
        int pindx = (int)((indx-1)/2);
        while(heap[pindx] < heap[indx] && indx != 0){
            swap(heap[indx],heap[pindx]);
            indx = pindx;
            pindx = (int)((indx-1)/2);
        }
    }
}
*/
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
void buildHeapOptimisedHelper(vector<int> &heap,int indx){
    if(indx >= heap.size()){
        return;
    }

    int leftchild = indx*2 +1;
    int rightchild = indx*2 + 2;
    int largestAmongThem = indx;

    if(leftchild >=heap.size()){ // if left child is not present then obviously right will not be there
        return;
    }
    if(leftchild<heap.size() and heap[largestAmongThem] < heap[leftchild])
        largestAmongThem = leftchild;
    if(rightchild<heap.size() and heap[largestAmongThem] < heap[rightchild])
        largestAmongThem = rightchild;
    
    if(indx != largestAmongThem){
        swap(heap[indx],heap[largestAmongThem]);
        buildHeapOptimisedHelper(heap,largestAmongThem);
    }
    else
        return;

}
void buildHeapOptimised(vector<int> &heap){
    for(int i=heap.size()-1; i>=0; i--){
        buildHeapOptimisedHelper(heap,i);
    }
}

/*  Heap sort code

    time complexity = O(nlogn)
    bcoz time for heapify is logn and we are doing it n time  so total O(nlogn)

void downHeapifyHeapSort(vector<int> &heap , int indx, int upto){
    int leftIndx = 2*indx + 1;
    int rightIndx = 2*indx + 2;
    if(leftIndx >=upto and rightIndx >= upto){
        return;
    }
    int largestIndx = indx;
    if(leftIndx < upto and heap[leftIndx]>heap[largestIndx]){
        largestIndx = leftIndx;
    }
    if(rightIndx < upto and heap[rightIndx]>heap[largestIndx]){
        largestIndx = rightIndx;
    }
    if(largestIndx == indx)
        return;
    swap(heap[largestIndx],heap[indx]);
    downHeapifyHeapSort(heap,largestIndx,upto);

}
void heapSort(vector<int> &heap){

    for(int i =0; i<heap.size()-1; i++){
        swap(heap[0],heap[heap.size()-1-i]);
        display(heap);
        downHeapifyHeapSort(heap,0,heap.size()-1-i);
        
    }
}

*/ 

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
    deletePeak(heap);
    display(heap);
   
    return 0;
}

```
Heap Live

``` c
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
```
