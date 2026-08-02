// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
int preIdx = 0;
TreeNode *build(vector<int> &preorder, int start, int end)
{
  if (start > end)
    return NULL;
  int rootVal = preorder[preIdx++];
  TreeNode *root = new TreeNode(rootVal);
  int mid = mp[rootVal];
  root->left = build(preorder, start, mid - 1);
  root->right = build(preorder, mid + 1, end);
  return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  int n = inorder.size();
  if (n == 0)
    return NULL;
  for (int i = 0; i < n; i++)
  {
    mp[inorder[i]] = i;
  }
  return build(preorder, 0, n - 1);
}