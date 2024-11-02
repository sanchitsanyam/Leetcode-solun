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
    int dfs(TreeNode* curr){
        if(curr->left==NULL && curr->right==NULL){
            return 1;
        }
        int l=0,r=0;
        if(curr->left){
            l=dfs(curr->left);
        }
        if(curr->right){
            r=dfs(curr->right);
        }
        return 1+max(l,r);
        
    
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return dfs(root);
    }
};