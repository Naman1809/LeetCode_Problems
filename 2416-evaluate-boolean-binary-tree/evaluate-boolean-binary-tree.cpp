class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        // base case: leaf
        if (root->val < 2) return root->val;
        // or node
        else if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        // and node
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};