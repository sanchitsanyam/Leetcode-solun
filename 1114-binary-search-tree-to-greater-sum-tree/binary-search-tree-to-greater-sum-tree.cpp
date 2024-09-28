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
    void helper(TreeNode* root ,int& t){
        if(root==NULL)return;
        if(root->right!=NULL){
           helper(root->right, t); 
        }
        t+=root->val;
        root->val=t;
        if(root->left!=NULL){
            helper(root->left ,t);
        }

    }
    TreeNode* bstToGst(TreeNode* root) {
        int t=0;
        helper(root,t);
        return root;
    }
};