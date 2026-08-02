// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

#include <bits/stdc++.h>
using namespace std;

ListNode *reverseKGroup(ListNode *head, int k)
{
  // if(head == NULL || head->next == NULL) return head;
  ListNode *curr = head;
  int count = 0;
  while (curr && count < k)
  {
    curr = curr->next;
    count++;
  }
  if (count < k)
    return head;
  curr = head;
  ListNode *prev = NULL, *next = NULL;
  count = 0;
  while (curr && count < k)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
  if (next != NULL)
    head->next = reverseKGroup(next, k);
  return prev;
}