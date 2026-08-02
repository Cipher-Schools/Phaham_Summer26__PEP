// https://leetcode.com/problems/even-odd-tree/description/

bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    bool evenLevel = true;
    while(!q.empty()){
        int size = q.size();
        int prev = evenLevel ? INT_MIN : INT_MAX;
        for(int i=0;i<size;i++){
            TreeNode* front = q.front();
            q.pop();
            int nodeVal = front->val;
            if(evenLevel && (nodeVal%2 == 0 || prev >= nodeVal)) return false;
            if(!evenLevel && (nodeVal%2 != 0 || prev <= nodeVal)) return false;
            prev = nodeVal;
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        evenLevel = !evenLevel;
    }
    return true;
}