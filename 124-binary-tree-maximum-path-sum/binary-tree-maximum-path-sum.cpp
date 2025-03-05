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
    int res=INT_MIN;
    int h(TreeNode* root){
        if(root==nullptr)return 0;
        int lt= max(h(root->left),0);
        int rt= max(h(root->right),0);
       
        res=max(res,root->val+lt+rt);
        return root->val+max(rt,lt);
    }
    int maxPathSum(TreeNode* root) {
        int x=h(root);
        return res;
    }
};