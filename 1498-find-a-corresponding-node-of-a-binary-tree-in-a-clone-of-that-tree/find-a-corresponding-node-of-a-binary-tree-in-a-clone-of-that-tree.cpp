/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void dfs(TreeNode* &ans,TreeNode* nodeO, TreeNode* nodeP , TreeNode* target){
        if(nodeO==NULL)return;
        if(nodeO->val==target->val){
            ans= nodeP;
            return;
        }    
        dfs(ans,nodeO->left,nodeP->left,target);
        dfs(ans,nodeO->right ,nodeP->right ,target);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
            TreeNode* ans=NULL;
            dfs(ans,original,cloned,target);
            return ans;
    }
};