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
    unordered_map<int,int>mp;
    bool helper(TreeNode*root, int level){
        if(root==NULL)return true;
        if(level&1){
            if(root->val&1)return false;
        }
        else if(!(root->val&1))return false;
        
        if(mp.find(level)!=mp.end()){
            if(level&1){
                if(mp[level]<=root->val)return false;
            }
            else if(mp[level]>=root->val)return false;
        }
        mp[level]=root->val;
        return helper(root->left,level+1)&&helper(root->right,level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
       return helper(root,0);
        
    }
};