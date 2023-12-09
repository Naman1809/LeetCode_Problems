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
      vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
      
        // if(root==NULL){
        //     return v;
        // }
        // inorderTraversal(root->left);
        // v.push_back(root->val);
        // inorderTraversal(root->right);
        // return v;
        
         stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                root=s.top();
                s.pop();
                v.push_back(root->val);
                root=root->right;
            }
          }
         return v;
        
        // vector<int> v;
        // TreeNode *curr=root;
        // while(curr!=NULL){
        //     if(curr->left==NULL){
        //         v.push_back(curr->val);
        //         curr=curr->right;
        //     }
        //     else{
        //         TreeNode* prev=curr->left;
        //         while(prev->right!=NULL&&prev->right!=curr)
        //         {
        //             prev=prev->right;
        //         }           
            
        //         if(prev->right==NULL){
        //             prev->right=curr;
        //             curr=curr->left;
        //         }
        //         else{
        //             prev->right=NULL;
        //              v.push_back(curr->val);
        //             curr=curr->right;
                   
        //         }
        //     }
        // }
        
        // return v;
    }
};