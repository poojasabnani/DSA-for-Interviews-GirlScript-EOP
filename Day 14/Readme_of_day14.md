# DSA DAY 14

## Topics Covered

* STL in C++

## Theory

[STL](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%2014/stl_pptx.pptx)

## Solved Problems

#### Problem 1.

Given a Binary tree. Print the top view of the Binary tree.

```c


void helper(Node* root , map<int,pair<int,int>> &mp,int x ,int y){
        if(root == nullptr){
            return;
        }
        // recursive case
        helper(root->left , mp, x-1,y+1);
        if(mp.find(x) == mp.end() or mp[x].second > y ){
            mp[x] = make_pair(root->data,y);
        }
        helper(root->right, mp, x+1, y+1);
        return;

    }
    void topView(Node * root) {

        map<int , pair<int,int>  > mp;
        helper(root, mp , 0 , 0);

        for(auto it = mp.begin(); it !=mp.end(); it++){
            cout<<it->second.first<<" ";
        }
    }
```
#### Problem 2.

Given an array. Print the sum of all the contiguous subarrays of that array.

```c
#include<iostream>
using namespace std;

long long allSubarraySum_bruteforce(int arr[],int n){

    // time complexity  =  O(n^3)
    // space complexity = O(1)
    
    long long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k = i; k<=j; k++){
                ans += arr[k];
            }
        }
    }
    return ans;
}


long long allSubarraySum_better(int arr[],int n){

    // time complexity = O(n^2)
    // space complexity = O(1)
    
    // generally the space complexity for commulative sum array method goes 
    // to O(N) because we need to maintain the main array also(in some cases)

    // preparing commulative sum array...
    for(int i=0; i<n; i++){
        if(i != 0){
            arr[i] = arr[i-1]+arr[i];
        }
    }
        // arr will be the commulative sum array

    // calculating the sum of all possible subarrays...
    long long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            ans = ans + arr[j];
            if(i!=0){
                ans = ans - arr[i-1];
            }
        }
    }
    return ans;
}

long long allSubarraySum_optimised(int arr[],int n){

    // time complexity = O(n)
    // space complexity = O(1)
    
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += arr[i]*((i+1)*(n-i));
    }
    return ans;
}

int main(){
    int n = 6;
    int arr[n] = {1,2,3,4,5,6};
    long long ALL_SUBARRAY_SUM = allSubarraySum_better(arr,n);
    cout<<"ALL_SUBARRAY_SUM : " << ALL_SUBARRAY_SUM<<endl;
    return 0;
}
```

#### problem 3.

Given an array "A". for every element print the multiplication of every number except that number.

example: 
    
```c
input :  1,  2,  3,  4,  5
output:  120, 60, 40, 30, 24
```
We have the arraay elements in the range -75 <= Ai <= 200

Try doing it without using division anywhere.

```c
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
```
