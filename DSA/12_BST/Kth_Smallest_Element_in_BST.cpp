// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <bits/stdc++.h>
using namespace std;

// by building inorder array

vector<int>ans;
void inorder(TreeNode *root, int k)
{
  if (!root)
    return;
  inorder(root->left, k);
  ans.push_back(root->val);
  inorder(root->right, k);
}
int kthSmallest(TreeNode *root, int k)
{
  inorder(root, k);
  return ans[k-1];
}

// using inorder only

int count = 0;
int ans;
void inorder(TreeNode *root, int k)
{
  if (!root)
    return;
  inorder(root->left, k);
  count++;
  if (count == k)
    ans = root->val;
  inorder(root->right, k);
}
int kthSmallest(TreeNode *root, int k)
{
  inorder(root, k);
  return ans;
}