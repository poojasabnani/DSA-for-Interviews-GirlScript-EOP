/*
    Given a string containing only three types of characters: '(', ')' and '*',
    write a function to check whether this string is valid. We define the validity of a string by these rules:

    1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
    3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    5. An empty string is also valid.

    examples:
    input : (*)
    output : balanced

    2.
    input : (*)
    output : balanced

    3.
    input : ()()()()*(
    output : not balanced
    
    4.
    input : *)()(*()*(*
    output: balanced

    5. 
    input : (((*)))
    output : balanced

    6. 
    input : *(((*))))
    output : balanced

*/
#include<bits/stdc++.h>
#define Stack stack<int>
using namespace std;
bool sol(string s){
    int n = s.size();
    Stack openBracs,stars;
    for(int i=0; i<n; i++){
        char ch = s[i];
        if(ch == '('){
            openBracs.push(i);
        }
        else if(ch == '*'){
            stars.push(i);
        }
        else {
            if(!openBracs.empty()){
                openBracs.pop();
            }
            else if(!stars.empty()){
                stars.pop();
            }
            else {
                return false;
            }
        }
    }
    while(!openBracs.empty() and !stars.empty()){
        if(openBracs.top()>stars.top())
            return false;
        else {
            openBracs.pop();
            stars.pop();
        }
    }
    
    return openBracs.empty(); // if we are able to nullify all the open brackets we return true
    // else false is returned... this handles both the situations
}
int main(){
    string in;
    cin>>in;
    bool isbalanced = sol(in);
    if(isbalanced == false){
        cout<<"Not Balanced\n";
    }
    else {
        cout<<"Balanced\n";
    }
    return 0;
}