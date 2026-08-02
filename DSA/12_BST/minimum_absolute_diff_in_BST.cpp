// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

#include <bits/stdc++.h>
using namespace std;

int prev = -1, minDiff = INT_MAX;
void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  if (prev != -1)
    minDiff = min(minDiff, root->val - prev);
  prev = root->val;
  inorder(root->right);
}
int getMinimumDifference(TreeNode *root)
{
  inorder(root);
  return minDiff;
}
