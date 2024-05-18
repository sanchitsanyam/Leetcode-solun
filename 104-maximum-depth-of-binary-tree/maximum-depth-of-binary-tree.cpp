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
    int maxDepth(TreeNode* root) {
        return depthHelper( root);
    }
};