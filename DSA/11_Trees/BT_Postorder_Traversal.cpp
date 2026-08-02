// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

void postorder(TreeNode* root, vector<int>&result){
    // left->right->root
    if(!root) return;
    postorder(root->left, result);
    postorder(root->right, result);
    result.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>result;
    postorder(root, result);
    return result;
}