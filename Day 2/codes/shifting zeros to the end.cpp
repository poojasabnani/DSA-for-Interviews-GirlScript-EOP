// problem : given an input array A. Shift all the 0's to the end maintaining 
// the relative order of nonzero elements.

// input ::  8, 0, 9, 0, 1, 7, 2, 0, 31, 72
// output :: 8, 9, 1, 7, 2, 31, 72, 0, 0, 0

// do this in O(N) time
// space O(1)


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