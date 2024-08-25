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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode *>s1;
        if(root==NULL){
            return v;
        }
        s1.push(root);
        while(!s1.empty()){
            TreeNode *node=s1.top();
            s1.pop();
            
            v.push_back(node->val);
            if(node->left){
                s1.push(node->left);
            }
            if(node->right){
                s1.push(node->right);
            }
        }
      reverse(v.begin(),v.end());
        return v;
        
    }
};