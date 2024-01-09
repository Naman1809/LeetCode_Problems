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
    vector<int>ans1,ans2;
    void helper1(TreeNode*root1){
         if(root1==NULL)return;
        if(root1->left==NULL&&root1->right==NULL){
            ans1.push_back(root1->val);
            return;
        }
        helper1(root1->left);
    helper1(root1->right);
    }
        void helper2(TreeNode*root2){
        if(root2==NULL)return;
        if(root2->left==NULL&&root2->right==NULL){
            ans2.push_back(root2->val);
            return;
        }
        helper2(root2->left);
    helper2(root2->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper1(root1);
        helper2(root2);
      
        return ans1==ans2;
    }
};