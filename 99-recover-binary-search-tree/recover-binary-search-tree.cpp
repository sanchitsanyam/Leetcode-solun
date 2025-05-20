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
    TreeNode* first=NULL;
    TreeNode* Second=NULL;
    TreeNode* prev=NULL;
    void in(TreeNode* root){
        if(root==NULL)return;
        in(root->left);
        if(prev && prev->val > root->val){
            if(!first)first=prev;
            Second=root;
        }
        prev=root;
        in(root->right);
    }
    void recoverTree(TreeNode* root) {
        in(root);
        swap(first->val,Second->val);
    }
};