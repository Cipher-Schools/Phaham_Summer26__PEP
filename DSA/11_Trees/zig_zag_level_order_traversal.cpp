// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>>result;
    if(!root) return result;
    queue<TreeNode*>q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>temp;
        for(int i=0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            temp.push_back(front->val);
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        if(!leftToRight) reverse(temp.begin(), temp.end());
        result.push_back(temp);
        leftToRight = !leftToRight;
    }
    return result;
}
