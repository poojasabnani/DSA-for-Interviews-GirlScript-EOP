/*
    given an array "A". for every element print the multiplication of every number
    except that number.
    ex: input :  1,  2,  3,  4,  5
       output:  120, 60, 40, 30, 24
    
    we have the arraay elements in the range -75 <= Ai <= 200

    try doing it without using division anywhere.
*/




#include<iostream>
using namespace std;





int main(){
    int n = 5;
    int arr[n] = {1,  2,  3,  4,  5};
    int leftMuli[n];
    int rightMulti[n];
    leftMuli[0] = 1;
    for(int i=1; i<n; i++){
        leftMuli[i] = leftMuli[i-1]*arr[i-1];
    }
    rightMulti[n-1] = 1;
    for(int i=n-2; i>= 0; i--){
        rightMulti[i] = rightMulti[i+1]*arr[i+1];
    }
    for(int i=0; i<n; i++){
        cout<<leftMuli[i]*rightMulti[i]<<" ";
    }
    return 0;
}