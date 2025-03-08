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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<pair<TreeNode* ,unsigned long long>> q;
       
        int maxWidth=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            unsigned long long minX=q.front().second;
            unsigned long long maxX=minX;
           
            for(int i=0;i<size;i++){
                auto p=q.front();
                q.pop();
                TreeNode* curr= p.first;
                unsigned long long x=p.second;
                maxX=max(maxX,x);
                if(curr->left)q.push({curr->left,2*x+1});
                if(curr->right)q.push({curr->right,2*x+2});
            }
            maxWidth=max(maxWidth,(int)(maxX-minX)+1);
        }
        return maxWidth;
    }
};
