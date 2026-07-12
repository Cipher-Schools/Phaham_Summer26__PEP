// lc - 234

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(ListNode* head) {
    // Step 1: find middle using slow/fast pointer
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    
    // Step 2: reverse second half
    ListNode* prev = nullptr, *curr = slow;
    while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
    
    // Step 3: compare first half with reversed second half
    ListNode* left = head, *right = prev;
    while (right) {
        if (left->val != right->val) return false;
        left = left->next; right = right->next;
    }
    return true;
}
// This combines two techniques: slow/fast pointer + in-place reversal
// Time O(n), Space O(1)