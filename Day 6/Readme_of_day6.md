# DSA DAY 6

## Topics Covered

* Introduction to Algorithms
* Sorting Algorithms

## Theory

[Sorting Algorithms](https://github.com/py93/DSA-for-Interviews-GirlScript-EOP/blob/master/Day%206/Day6.pptx?raw=true)

## Quiz

[Take the Quiz](https://forms.gle/k8bFPqiGBhgcEfFF8)

## Solved Problems

Given a row and a column wise sorted 2D matrix. Find whether an element x is present in the 2D array or not.

```c
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

```
