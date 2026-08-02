// https://leetcode.com/problems/symmetric-tree/

bool mirrorTree(TreeNode* l, TreeNode* r) {
    if(!l && !r) return true;
    if((!l && r) || (l && !r)) return false;
    if(l->val != r->val) return false;
    return mirrorTree(l->left, r->right) && mirrorTree(l->right, r->left);
}
bool isSymmetric(TreeNode* root) {
    return mirrorTree(root->left, root->right);
}