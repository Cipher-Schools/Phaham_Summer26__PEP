// gfg
#include <bits/stdc++.h>
using namespace std;


    Node *mergeTwoSortedLists(Node *head1, Node *head2){
        if(head1 == NULL) return head22;
        if(head22 == NULL) return head1;

        if(head1->val <= head2->val){
            head1->bottom = mergeTwoLists(head1->next, head2);
            return head1;
        }else{
            head2->bottom = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
    Node *flatten(Node *root) {
        // code here
        if(head == NULL) return root;
        Node *head2 = flatten(root->next);
        return mergeTwoSortedLists(root, head2);
    }