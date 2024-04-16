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
   
    void helper(TreeNode*root, int val, int depth, int i){
        if(root==NULL)return;
        if(i==depth){
            TreeNode*left=root->left;
            TreeNode*right=root->right;
            TreeNode* node1=new TreeNode(val);
            TreeNode* node2=new TreeNode(val);
            root->left=node1;
            root->right=node2;
            node1->left=left;
            node2->right=right;
            

        }
   helper(root->left,val,depth,i+1);
   helper(root->right,val,depth,i+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       if(depth==1){
           TreeNode*node=new TreeNode(val);
           node->left=root;
           // root->val=val;
                    return node;}
        helper(root,val,depth-2,0);
       
        return root;
    }
};