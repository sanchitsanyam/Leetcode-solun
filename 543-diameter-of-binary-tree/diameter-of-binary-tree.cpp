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
    int res=0;
    int h(TreeNode* root){
        if(root==nullptr)return 0;
        int lt= h(root->left);
        int rt= h(root->right);
        res=max(res,lt+rt);
        return 1+max(lt,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int x=h(root);
       return res;
    }
};