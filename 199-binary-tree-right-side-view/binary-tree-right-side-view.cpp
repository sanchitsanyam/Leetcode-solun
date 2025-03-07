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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int siz=q.size();
            int lastValue=-1;
            for(int i=0;i<siz;i++){
                TreeNode* curr = q.front();
                q.pop();
                lastValue=curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);

            }
            ans.push_back(lastValue);
            
        } 
        
        return ans;
        
    }
};