// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

#include <bits/stdc++.h>
using namespace std;

vector<Node*> findPreSuc(Node* root, int key) {
    Node *pre = NULL, *suc = NULL;
    Node *curr = root;

    // Search for the key while updating possible predecessor/successor
    while (curr) {
        if (curr->data == key)
            break;
        else if (key < curr->data) {
            suc = curr;          // current can be successor
            curr = curr->left;
        } else {
            pre = curr;          // current can be predecessor
            curr = curr->right;
        }
    }

    // If key is found
    if (curr) {
        // Predecessor = maximum in left subtree
        if (curr->left) {
            Node* temp = curr->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        // Successor = minimum in right subtree
        if (curr->right) {
            Node* temp = curr->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }

    return {pre, suc};
}