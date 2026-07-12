// gfg

#include <bits/stdc++.h>
using namespace std;

bool searchKey(Node* head, int key) {
    // Code here
    Node *temp = head;
    while(temp!=NULL){
        if(temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}