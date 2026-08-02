// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
using namespace std;

vector<int> rightSideView(TreeNode *root)
{
  vector<int> result;
  if (!root)
    return result;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
      TreeNode *front = q.front();
      q.pop();
      if (i == size - 1)
        result.push_back(front->val);
      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }
  }
  return result;
}