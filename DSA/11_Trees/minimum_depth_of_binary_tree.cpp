// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

int minDepth(TreeNode *root)
{
  if (!root)
    return 0;
  if (!root->left)
    return 1 + minDepth(root->right);
  if (!root->right)
    return 1 + minDepth(root->left);
  return 1 + min(minDepth(root->left), minDepth(root->right));
}
