#include<bits/stdc++.h>
#define Stack stack<char>
// guys i have used STL to make code shorter 
// i will be teaching about STL Later in this course(very useful)
// for now assume there is a Stack class :))
using namespace std;
bool sol(string arr){
    if(arr.size()%2 !=0 ){ 
        // if odd length ..then can never be balanced
        return false;
    }
    Stack s;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == '('){
            s.push(arr[i]);
        }
        else if(arr[i] == ')') {
            if(!s.empty()){
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
   
    string in;
    cin>>in;
    //cout<<in<<endl;
    bool isbalanced = sol(in);
    if(isbalanced == false){
        cout<<"Not Balanced \n";
    }
    else {
        cout<<"Balanced \n";
    }

    return 0;
}