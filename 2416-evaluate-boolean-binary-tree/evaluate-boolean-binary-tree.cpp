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
    bool help(TreeNode* node){
        if(node->left==NULL || node->right==NULL){
            if(node->val==0)return false;
            else return true;
        }
        else{
            if(node->val==2){
                return help(node->left)||help(node->right);
            }
            else{
                return help(node->left) && help(node->right);
            }
        }
    }
    bool evaluateTree(TreeNode* root) {
        return help(root);
    }
};