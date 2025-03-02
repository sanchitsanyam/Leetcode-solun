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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        s1.push(root);
        vector<vector<int>> ans;
        int i=0;
        if(root==nullptr)return ans;
        ans.push_back({root->val});
        while(!s1.empty()){
            vector<int> a;
            i++;
            stack<TreeNode*> s2;
            while(!s1.empty()){
                TreeNode* curr=s1.top();
                s1.pop();
                if(i%2==0){
                    if(curr->left!=nullptr)a.push_back(curr->left->val);
                    if(curr->left!=nullptr)s2.push(curr->left);
                    if(curr->right!=nullptr)a.push_back(curr->right->val);
                    if(curr->right!=nullptr)s2.push(curr->right);
                }
                else{
                    if(curr->right!=nullptr)a.push_back(curr->right->val);
                    if(curr->right!=nullptr)s2.push(curr->right);
                    if(curr->left!=nullptr)a.push_back(curr->left->val);
                    if(curr->left!=nullptr)s2.push(curr->left);
                }    
            }
            if(a.size()!=0)ans.push_back(a);
            s1=s2;
        }
        return ans;
        
    }
};