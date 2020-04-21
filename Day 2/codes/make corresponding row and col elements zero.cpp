/*
    problem: given a matrix, if 0 is encoundered, make all the elements in
    corresponding row and column as 0. 
    example :
        1 2 0 4         0 0 0 0
        1 3 1 6   :::>  1 3 0 6
        9 4 5 1         9 4 0 1

    required time : O(m*n)
*/




#include<iostream>
#include<cstring>
using namespace std; 
int main(){
    
    int m = 4;
    int n = 4;
    int arr[m][n] = {{1,2,3,0},
                     {0,4,5,6},
                     {7,11,2,1},
                     {2,8,0,19}};
    int rowFlag[m];
    int colFlag[n]; 
    // remember memset only works for (0 or -1) 
    // because it works on bits and is defined in cstring headerfile
    memset(rowFlag,-1,sizeof(rowFlag));
    memset(rowFlag,-1,sizeof(colFlag));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                rowFlag[i] = 0;
                colFlag[j] = 0;
            }
        }
    }
    // modifying the array
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(rowFlag[i]==0 or colFlag[j] == 0){
                arr[i][j] = 0;
            }
        }
    }
    // printing the array
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}