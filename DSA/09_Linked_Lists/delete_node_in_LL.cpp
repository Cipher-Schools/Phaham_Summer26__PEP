// https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

void deleteNode(ListNode *node)
{
  node->val = node->next->val;
  node->next = node->next->next;
}