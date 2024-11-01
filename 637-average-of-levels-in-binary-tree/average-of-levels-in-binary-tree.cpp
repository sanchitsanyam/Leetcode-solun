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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* r=q.front();
                q.pop();
                v.push_back(r->val);
                if(r->left)
                   q.push(r->left);
                if(r->right)
                   q.push(r->right);   
            }
            double k=0;
            for(auto i:v){
                k+=i;
            }
            ans.push_back((double)k/(double)(v.size()));
            v.clear();
            

        }
        return ans;
        
    }
};