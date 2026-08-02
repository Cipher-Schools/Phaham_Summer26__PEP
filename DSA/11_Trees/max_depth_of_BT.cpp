// https://leetcode.com/problems/maximum-depth-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;

int maxDepth(TreeNode *root)
{
  if (!root)
    return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
