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
// class Solution {
// public:
//     map<int,int>mp;
//     int pseudoPalindromicPaths (TreeNode* root) {
//         if(root==NULL)return 0;
//         mp[root->val]++;
//         if(root->left==NULL&&root->right==NULL){
            
//             int a=0;
//             for(auto it:mp){
//                 if(it.second%2)a++;
//             }
//             if(a>1)return 0;
//              return 1;
//         }
   
//         int l=pseudoPalindromicPaths(root->left);
//         int r=pseudoPalindromicPaths(root->right);
// mp[root->val]--;
//         return l+r;
//     }
// };

class Solution {
public:
    map<int,int>mp;
    int ans=0;
    void helper(TreeNode*root){
        if(root==NULL)return;
        mp[root->val]++;
        if(root->left==NULL&&root->right==NULL){
            int c=0;
            for(auto it :mp){
                if(it.second%2)c++;
            }
            if(c<=1)ans++;
            
        }
        
        helper(root->left);
        helper(root->right);
        mp[root->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
helper(root);
        return ans;
    }
};