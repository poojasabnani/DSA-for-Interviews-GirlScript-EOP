#include <bits/stdc++.h>
#define Queue queue<char> 
using namespace std;
// if you dont know about stl just assume we have a Queue class

// something like this...
// class Queue {
//     public:
//         void push(char ch); // insert char at the end
//         void pop(); // deletes char from front
//         char front(); // return the char at the front
// }

int findAns(string s, int changeallowed)
{
    int ans = 0;
    int na, nb;
    na = nb = 0;
    int changemade = 0;
    int currentans = 0;
    Queue q;
    int indx = 0;
    while (indx <= s.length()-1)
    {
        if (changemade < changeallowed or (na>=nb and s[indx] == 'a') or (nb>=na and s[indx] == 'b'))
        {
            if (s[indx] == 'a')
            {
                na++;
            }
            else
            {
                nb++;
            }
            q.push(s[indx]);
            changemade = min(na,nb);
            indx++;
            currentans++;
        }
        else {
            char whatIsDel = q.front();
            q.pop();
            if(whatIsDel == 'a')
                na--;
            else if(whatIsDel == 'b')
                nb--;
            
            changemade = min(na,nb);
            currentans--;
        }

        if (currentans > ans)
            ans = currentans;
    }

    return ans;
}
int main()
{
    int change;
    cin >> change;
    string s;
    cin >> s;

    cout << findAns(s, change);
    return 0;
}