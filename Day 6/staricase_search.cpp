#include<iostream>
using namespace std;
int main() {
	int m,n;
	cin>>m>>n;
	int arr[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++)
			cin>>arr[i][j];
	}
	int key;
	cin>>key;
	int si=0; 
	int sj = n-1;
	bool found = false;
	while(si<m && sj>=0){
		if(arr[si][sj] == key){
			found = true;
			break;
		} else{
			if(key>arr[si][sj]){
				si +=1;
			} else{
				sj -= 1;
			}
		}
	}
	found == true ? cout<<"1" : cout<<"0";
	return 0;
}
