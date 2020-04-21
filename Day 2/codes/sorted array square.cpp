#include<iostream>
using namespace std;
// given a sorted array print return the square of the array also in sorted order
// required time complexity : O(N)
// ex : input: -11, -9, -6, 2, 5, 8, 10, 12
//      output: 4, 25, 36, 64, 81, 100, 121, 144

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