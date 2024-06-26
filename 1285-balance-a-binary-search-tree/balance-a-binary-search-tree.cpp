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
    void inorder(TreeNode*root, vector<int>&ans){
        if(root==NULL)return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode*helper(vector<int>&ans,int low, int high){
        if(low>high)return NULL;
        int mid=(low+high)/2;
        TreeNode*node=new TreeNode(ans[mid]);
        node->left=helper(ans,low,mid-1);
        node->right=helper(ans,mid+1,high);
    return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
       return helper(ans,0,ans.size()-1);
        
    }
};