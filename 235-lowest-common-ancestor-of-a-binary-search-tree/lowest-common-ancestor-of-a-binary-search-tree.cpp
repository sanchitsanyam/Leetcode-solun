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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int r1=p->val;
        int r2=q->val;
        int s=min(r1,r2);
        int e=max(r1,r2);
        TreeNode* curr=root;
        while(curr){
            int x=curr->val;
            if(x<s)curr=curr->right;
            else if(x>e){
                curr=curr->left;
            }
            else{
                return curr;
            }
        }
        return nullptr;
        
    }
};