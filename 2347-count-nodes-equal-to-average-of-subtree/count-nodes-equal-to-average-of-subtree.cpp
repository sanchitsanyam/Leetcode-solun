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
    
    int help(TreeNode* root ){
        if(root==NULL)return 0;
        int sum=root->val;
        sum+=help(root->left);
        sum+=help(root->right);
        return sum;
    }
    int sz(TreeNode* root){
        if(root==NULL)return 0;
        int sum=1;
        sum+=sz(root->left);
        sum+=sz(root->right);
        return sum;
        
    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        int x=help(root);
        int y=sz(root);
        
        int z=x/y;
        int ans=0;
        if(z==root->val)ans++;
        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);
        return ans;
    }
};