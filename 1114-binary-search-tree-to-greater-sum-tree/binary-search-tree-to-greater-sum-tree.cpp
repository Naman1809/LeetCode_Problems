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
//     void inorder(TreeNode*root,vector<int>&ans){
//         if(root==NULL)return;
//         inorder(root->left,ans);
//         ans.push_back(root->val);
//         inorder(root->right,ans);
//     }
//     void helper(TreeNode*&root, unordered_map<int,int>&mp){
//         if(root==NULL)return;
//         root->val=mp[root->val];
//         helper(root->left,mp);
//         helper(root->right,mp);
//     }
//     TreeNode* bstToGst(TreeNode* root) {
//         vector<int>ans;
//         inorder(root,ans);
//         int n=ans.size();
//         vector<int>ans2(n);
//         unordered_map<int,int>mp;
//         int sum=0;
        
//         for(int i=n-1;i>=0;i--){
//                 sum+=ans[i];
//     mp[ans[i]]=sum;
//         }
//         helper(root,mp);
//     return root;
//     }
    
       int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) bstToGst(root->right);
        pre = root->val = pre + root->val;
        if (root->left) bstToGst(root->left);
        return root;
    }
};