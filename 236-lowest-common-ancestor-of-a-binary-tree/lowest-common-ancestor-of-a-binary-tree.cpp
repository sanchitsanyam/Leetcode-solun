/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* T(TreeNode* root ,TreeNode* p, TreeNode* q){
        if(root==NULL){
           return nullptr;
        }
        if(root==p || root==q){
            return root;
        }
        TreeNode * r1=T(root->left,p,q);
        TreeNode * r2=T(root->right,p,q);
        if(r1!=nullptr && r2!=nullptr){
            return root;
        }
        return r1!=nullptr? r1:r2;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return T(root,p,q);
    }
};