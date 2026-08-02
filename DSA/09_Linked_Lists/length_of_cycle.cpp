// gfg

#include <bits/stdc++.h>
using namespace std;

int length(Node *head){
  Node *slow = head, *fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast){
      Node *temp = slow->next;
      int count = 1;
      while(temp!=slow){
        count++;
        temp = temp->next;
      }
    }
  }
  return count;
}