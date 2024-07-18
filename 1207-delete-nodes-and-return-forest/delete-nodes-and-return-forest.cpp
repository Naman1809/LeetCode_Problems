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
    vector<TreeNode*>ans;
    unordered_map<int,int>mp;
TreeNode* helper(TreeNode*root){
        // if(root==NULL)return false;
        // if(root->left==NULL&&root->right==NULL){
        //     if(mp[root->val]>0)return false;
        //     else return true;
        // }
        // bool l=helper(root->left);
        // bool r=helper(root->right);
        // if(l)ans.push_back(root->left);
        // if(r)ans.push_back(root->right);
if(root==NULL)    return NULL;
    root->left=helper(root->left);
    root->right=helper(root->right);
    if(mp[root->val]>0){
        if(root->left)ans.push_back(root->left);
        if(root->right)ans.push_back(root->right);
        return NULL;
    }
return root;
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root==NULL)return ans;
        for(int i=0;i<to_delete.size();i++){
            mp[to_delete[i]]++;
        }
        helper(root);
        if(mp[root->val]==0)ans.push_back(root);
        return ans;
        
    }
};