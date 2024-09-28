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
    void insertHelper(TreeNode* root ,TreeNode*& node){
       
        if(root->val > node->val){
            if(root->left==NULL){
                root->left=node;
            }
            else{
                insertHelper( root->left , node); 
            }  
        }
        else{
            if(root->right==NULL){
                root->right=node;
            }
            else{
                insertHelper( root->right , node);
            }
           
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(root==NULL)return node;
        insertHelper(root ,node);
        return root;
    }
};