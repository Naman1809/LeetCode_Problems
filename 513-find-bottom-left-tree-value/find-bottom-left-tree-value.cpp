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
    // map<int,int>mp;
    // int height(TreeNode*root){
    //     if(root==NULL)return 0;
    //     return 1+max(height(root->left),height(root->right));
    // }
    void helper(TreeNode*root,int i, int& h, int &maxi){
        if(root==NULL)return;
                    
        
        
        helper(root->left,i+1,h,maxi);
        
        helper(root->right,i+1,h,maxi);
    if(i>h){
        maxi=root->val;
        h=i;
    }
    }
    int findBottomLeftValue(TreeNode* root) {
    
        int maxi=root->val;
        int h=0;
        helper(root,0,h,maxi);
        return maxi;
        
    }
};