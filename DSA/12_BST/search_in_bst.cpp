// https://leetcode.com/problems/search-in-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

TreeNode *searchBST(TreeNode *root, int val)
{
  if (!root)
    return NULL;
  if (val == root->val)
    return root;
  else if (val < root->val)
    return searchBST(root->left, val);
  else
    return searchBST(root->right, val);
}