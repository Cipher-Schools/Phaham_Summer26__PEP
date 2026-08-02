//

#include <bits/stdc++.h>
using namespace std;

// using priority queue -
// TC - O(n*log(k)), SC - O(k)
struct cmp
{
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{

  priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

  for (auto node : lists)
  {
    if (node)
      pq.push(node);
  }

  ListNode dummy(-1);
  ListNode *tail = &dummy;

  while (!pq.empty())
  {
    ListNode *curr = pq.top();
    pq.pop();

    tail->next = curr;
    tail = tail->next;

    if (curr->next)
      pq.push(curr->next);
  }

  return dummy.next;
}

// using recursion - merge two sorted LL way
// TC - O(n*k), SC - O(1)

ListNode *mergeTwoSortedLL(ListNode *list1, ListNode *list2)
{
  if (!list1)
    return list2;
  if (!list2)
    return list1;
  ListNode *head;
  if (list1->val <= list2->val)
  {
    head = new ListNode(list1->val);
    list1 = list1->next;
  }
  else
  {
    head = new ListNode(list2->val);
    list2 = list2->next;
  }
  ListNode *curr = head;
  while (list1 && list2)
  {
    if (list1->val <= list2->val)
    {
      curr->next = list1;
      curr = curr->next;
      list1 = list1->next;
    }
    else
    {
      curr->next = list2;
      curr = curr->next;
      list2 = list2->next;
    }
  }
  while (list1)
  {
    curr->next = list1;
    curr = curr->next;
    list1 = list1->next;
  }
  while (list2)
  {
    curr->next = list2;
    curr = curr->next;
    list2 = list2->next;
  }
  return head;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
  int n = lists.size();
  ListNode *merged = new ListNode(INT_MIN);
  ListNode *head = merged;
  for (int i = 0; i < n; i++)
  {
    if (lists[i] == NULL)
      continue;
    merged = mergeTwoSortedLL(merged, lists[i]);
  }
  return merged->next;
}