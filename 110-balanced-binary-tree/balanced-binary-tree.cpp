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
    
    int depthHelper(TreeNode* root){
        if(root==NULL) return 0;
        return max(depthHelper(root->left),depthHelper(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
       int lh=depthHelper(root->left);
       int rh=depthHelper(root->right);
       int absdiff=abs(lh-rh);
       if(absdiff>1)return false;
       return isBalanced(root->left) && isBalanced( root->right);
    }
};