// https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

int sumBT(Node* root) {
    // code here
    if(!root) return 0;
    return root->data + sumBT(root->left) + sumBT(root->right);
}
