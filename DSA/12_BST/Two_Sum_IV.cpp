// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <bits/stdc++.h>
using namespace std;

// by building inorder array

vector<int> ans;
void inorder(TreeNode *root)
{
  if (!root)
    return;
  inorder(root->left);
  ans.push_back(root->val);
  inorder(root->right);
}
bool findTarget(TreeNode *root, int k)
{
  inorder(root);
  int n = ans.size();
  int start = 0, end = n - 1;
  while (start < end)
  {
    int sum = ans[start] + ans[end];
    if (sum == k)
      return true;
    else if (sum > k)
      end--;
    else
      start++;
  }
  return false;
}

// using set -

set<int> st;
bool inorder(TreeNode* root, int k) {
    if (!root) return false;

    bool left = inorder(root->left, k);
    if (left) return true;

    if (st.count(k - root->val))
        return true;

    st.insert(root->val);

    return inorder(root->right, k);
}
bool findTarget(TreeNode* root, int k) { 
    return inorder(root, k); 
}