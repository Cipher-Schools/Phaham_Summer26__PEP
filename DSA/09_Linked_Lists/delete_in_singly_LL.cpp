// https://www.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1

#include <bits/stdc++.h>
using namespace std;

Node *deleteNode(Node *head, int x)
{
  // code here
  Node *temp = head;
  if (x == 1)
    head = head->next;
  for (int i = 1; i < x - 1; i++)
  {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  return head;
}