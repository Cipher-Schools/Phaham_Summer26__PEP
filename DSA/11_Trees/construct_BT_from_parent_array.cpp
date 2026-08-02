// https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

#include <bits/stdc++.h>
using namespace std;

Node *createTree(vector<int> &parent)
{
  // code here
  int n = parent.size();
  vector<Node *> nodes(n);
  for (int i = 0; i < n; i++)
  {
    nodes[i] = new Node(i);
  }
  Node *root = NULL;
  for (int i = 0; i < n; i++)
  {
    if (parent[i] == -1)
    {
      root = nodes[i];
    }
    else
    {
      Node *par = nodes[parent[i]];
      if (!par->left)
        par->left = nodes[i];
      else
        par->right = nodes[i];
    }
  }
  return root;
}