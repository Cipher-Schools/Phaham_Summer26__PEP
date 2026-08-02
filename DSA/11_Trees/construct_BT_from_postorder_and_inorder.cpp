// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;
int postIdx;
TreeNode *build(vector<int> &postorder, int start, int end)
{
  if (start > end)
    return NULL;
  int rootVal = postorder[postIdx--];
  TreeNode *root = new TreeNode(rootVal);
  int mid = mp[rootVal];
  root->right = build(postorder, mid + 1, end);
  root->left = build(postorder, start, mid - 1);
  return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
  int n = inorder.size();
  if (n == 0)
    return NULL;
  postIdx = n - 1;
  for (int i = 0; i < n; i++)
  {
    mp[inorder[i]] = i;
  }
  return build(postorder, 0, n - 1);
}
