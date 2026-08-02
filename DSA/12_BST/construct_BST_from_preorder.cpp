// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

int preIdx = 0;
TreeNode *buildTree(vector<int> &preorder, int minVal, int maxVal)
{
  if (preIdx == preorder.size())
    return NULL;
  int rootVal = preorder[preIdx];
  if (rootVal < minVal || rootVal > maxVal)
    return NULL;
  preIdx++;
  TreeNode *root = new TreeNode(rootVal);
  root->left = buildTree(preorder, minVal, rootVal);
  root->right = buildTree(preorder, rootVal, maxVal);
  return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
  return buildTree(preorder, INT_MIN, INT_MAX);
}