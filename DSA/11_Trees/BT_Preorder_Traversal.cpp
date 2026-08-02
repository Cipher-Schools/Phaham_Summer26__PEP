// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

void preorder(TreeNode *root, vector<int> &result)
{
  // root->left->right
  if (!root)
    return;
  result.push_back(root->val);
  preorder(root->left, result);
  preorder(root->right, result);
}

vector<int> preorderTraversal(TreeNode *root)
{
  vector<int> result;
  preorder(root, result);
  return result;
}