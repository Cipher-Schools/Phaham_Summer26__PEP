#include <bits/stdc++.h>
using namespace std;

// lc - 328

ListNode* oddEvenList(ListNode* head) {
    ListNode* odd = head, *even = head->next, *evenHead = even;
    while(even && even->next){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHEad;
    return head;
}