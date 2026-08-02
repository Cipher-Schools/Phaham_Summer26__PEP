// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

vector<int> bottomView(Node *root)
{
  map<int, int> mp;           //<HD, node->val>
  queue<pair<Node *, int>> q; // <node, HD>
  q.push({root, 0});
  while (!q.empty())
  {
    auto front = q.front();
    q.pop();
    int currHD = front.second;
    Node *currNode = front.first;
    mp[currHD] = currNode->data;
    if (currNode->left)
      q.push({currNode->left, currHD - 1});
    if (currNode->right)
      q.push({currNode->right, currHD + 1});
  }
  vector<int> result;
  for (auto it : mp)
  {
    result.push_back(it.second);
  }
  return result;
}