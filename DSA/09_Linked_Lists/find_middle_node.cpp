// lc - 876

#include <bits/stdc++.h>
using namespace std;

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;         // moves 1 step
        fast = fast->next->next;   // moves 2 steps
    }
    return slow;  // when fast hits end, slow is at middle
}
// Time O(n), Space O(1)