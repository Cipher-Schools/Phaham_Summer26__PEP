// lc - 19

#include <bits/stdc++.h>
using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0); dummy.next = head;         // dummy node simplifies edge cases
    ListNode* slow = &dummy, *fast = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;  // advance fast n+1 steps
    while (fast) { slow = slow->next; fast = fast->next; }
    slow->next = slow->next->next;                // skip the target node
    return dummy.next;
}
// The dummy node handles the edge case where head itself must be deleted (n == length)