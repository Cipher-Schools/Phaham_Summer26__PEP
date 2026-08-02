// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

vector<int> topView(Node *root)
{
  // code here
  vector<int> ans;
  if (!root)
    return ans;
  int HD = 0;
  queue<pair<Node *, int>> q;
  map<int, int> mp; // Hd, val of node
  q.push({root, HD});
  while (!q.empty())
  {
    auto node = q.front();
    q.pop();
    Node *front = node.first;
    int hd = node.second;
    // check visiting first time or not
    if (mp.find(hd) == mp.end())
    {
      mp[hd] = front->data;
    }

    if (front->left)
      q.push({front->left, hd - 1});
    if (front->right)
      q.push({front->right, hd + 1});
  }
  for (auto it : mp)
  {
    ans.push_back(it.second);
  }
}