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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int ,int> m;
        queue<TreeNode*>q;
        vector<int> bfs;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr =q.front();
            q.pop();
            bfs.push_back(curr->val);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        for(int i=0;i<bfs.size();i++){
            if(m[k-bfs[i]])return true;
            m[bfs[i]]++;
        }
        return false;
        
    }
};