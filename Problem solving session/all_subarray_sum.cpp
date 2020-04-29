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