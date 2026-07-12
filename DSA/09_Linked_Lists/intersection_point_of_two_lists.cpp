// lc - 160

#include <bits/stdc++.h>
using namespace std;

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA, *b = headB;
    while (a != b) {
        a = a ? a->next : headB;   // when a hits null, redirect to headB
        b = b ? b->next : headA;   // when b hits null, redirect to headA
    }
    return a;   // either the intersection node, or nullptr (no intersection)
}
// If no intersection: both reach nullptr at the same time (after len(A)+len(B) steps)
// Time O(m+n), Space O(1) — no extra memory