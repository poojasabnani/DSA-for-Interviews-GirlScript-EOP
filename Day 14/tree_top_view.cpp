/* Given a binary tree. Print top view of binary tree */

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
