#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    // now printing
    for(int i=0; i<n; i++){
       
            int temp = i;
            for(int j=0; j<=i; j++){
                cout<<arr[n-temp-1][j]<<" ";
                temp--;
            }
            cout<<endl;
    
    }
    //now for upper half
    for(int i=1; i<n; i++){
        int temp = i;
        for(int j=0; j<n-i; j++){
            cout<<arr[j][temp]<<" ";
            temp++;
        }
        cout<<endl;
    }
    return 0;
}