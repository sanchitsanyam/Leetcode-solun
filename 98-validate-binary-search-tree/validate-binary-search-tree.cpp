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
    bool helper(TreeNode* root ,long long maxm , long long minm){
        if(root==NULL)return true;
        if(root->val >=maxm || root->val <= minm){
           return false;
        }
        bool opn1=helper( root->right , maxm , root->val);
        bool opn2=helper( root->left ,  root->val ,minm);
        return opn1 && opn2;
        
    }
    bool isValidBST(TreeNode* root) {
        long long maxm=LLONG_MAX;
        long long minm=LLONG_MIN;
        return helper(root ,maxm ,minm);

    }
};