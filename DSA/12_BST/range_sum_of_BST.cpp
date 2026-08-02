//https://leetcode.com/problems/range-sum-of-bst/description/

#include <bits/stdc++.h>
using namespace std;

int rangeSumBST(TreeNode *root, int low, int high)
{
  if (!root)
    return 0;
  if (root->val < low)
  {
    return rangeSumBST(root->right, low, high);
  }
  else if (root->val > high)
  {
    return rangeSumBST(root->left, low, high);
  }
  else
  {
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
  }
}