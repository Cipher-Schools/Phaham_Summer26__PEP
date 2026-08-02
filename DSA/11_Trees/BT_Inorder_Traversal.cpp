// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

void inorder(TreeNode *root, vector<int> &result)
{
  // left->root->right
  if (!root)
    return;
  inorder(root->left, result);
  result.push_back(root->val);
  inorder(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root)
{
  vector<int> result;
  inorder(root, result);
  return result;
}