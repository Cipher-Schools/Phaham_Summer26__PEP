// lc - 206

#include <bits/stdc++.h>
using namespace std;

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, *curr = head;
    while (curr) {
        ListNode* next = curr->next;  // save next
        curr->next = prev;            // flip arrow
        prev = curr;                  // advance prev
        curr = next;                  // advance curr
    }
    return prev;                      // prev is new head
}
// Time O(n), Space O(1) — in-place, only 3 pointers