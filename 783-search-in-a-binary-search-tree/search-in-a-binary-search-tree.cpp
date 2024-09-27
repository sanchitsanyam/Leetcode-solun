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
    void searchBSTHelper(TreeNode*& ans,TreeNode* root, int val){
        if(root==NULL)return;
        if(root->val== val){
            ans = root;
            return;
        } 
        
        if(val > root->val){
            searchBSTHelper(ans,root->right,val);
        }    
        else{
            searchBSTHelper(ans,root->left,val);
        }
            
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans=NULL;
        searchBSTHelper(ans , root,val);
        return ans;
    }
};