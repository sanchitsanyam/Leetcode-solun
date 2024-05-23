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
    bool isValidBST(TreeNode* root) {

       return isValidBSTHelper( root, LLONG_MAX , LLONG_MIN);
    }
    bool isValidBSTHelper(TreeNode* root, long long max, long long min){
        if(root==NULL )return true;
        if(((root->val) >=max) || ((root->val)<=min) )return false;
        return isValidBSTHelper( root->left, root->val, min) && isValidBSTHelper( root->right, max, root->val);
    }
};