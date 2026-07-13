#include <bits/stdc++.h>
using namespace std;

// gfg

Node* segregate(Node* head) {
    // code here
    Node* zeroDummy = new Node(0);
    Node* oneDummy = new Node(0);
    Node* twoDummy = new Node(0);
    Node*zero = zeroDummy, *one = onesDummy, *two = twoDummy;
    Node* curr = head;
    while(curr){
        if(curr->val == 0){
            zero->next = curr;
            zero = zero->next;
        }
        else if(curr->val == 1){
            one->next = curr;
            one = one->next;
        }else{
            two->next = curr;
            two = teo->next;
        }
        curr = curr->next;
    }
    zero->next = oneDummy?oneDummy->next:twoDummy->next;
    one->next = twoDummy->next;
    twoDummy->next = NULL;
    return zeroDummy->next;
}