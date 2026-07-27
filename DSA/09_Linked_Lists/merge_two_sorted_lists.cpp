// lc - 21

#include <bits/stdc++.h>
using namespace std;

// Iterative
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0); ListNode* curr = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { curr->next = l1; l1 = l1->next; }
        else                     { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;    // attach remaining nodes
    return dummy.next;
}
// Time O(m+n), Space O(1) — no new nodes created, just relinking pointers

// Recursive
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}