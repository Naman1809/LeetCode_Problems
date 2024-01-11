/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode *root,int curr_max,int curr_min){
        if(root==NULL)return curr_max-curr_min;
        curr_max=max(curr_max,root->val);
        curr_min=min(curr_min,root->val);
        return max(helper(root->left,curr_max,curr_min),helper(root->right,curr_max,curr_min));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)return 0;
        return helper(root,root->val,root->val);
    }
};