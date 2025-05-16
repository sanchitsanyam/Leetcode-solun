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
        while(!(s < curr->val && curr->val <e) || curr!=nullptr){
            int x=curr->val;
            if(s<x && e<x){
                if(curr->left)curr=curr->left;
            }
            else if(s>x && e>x){
                if(curr->right)curr=curr->right;
            }
            else{
                return curr;
            }
        }
        return curr;
        
    }
};