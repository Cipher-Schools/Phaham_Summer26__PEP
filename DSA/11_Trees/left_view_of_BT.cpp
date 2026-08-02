// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

vector<int> leftView(Node *root) {
    // code here
    vector<int>result;
    if(!root) return result;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            Node* front = q.front();
            q.pop();
            if(i==0) result.push_back(front->data);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
    return result;
}