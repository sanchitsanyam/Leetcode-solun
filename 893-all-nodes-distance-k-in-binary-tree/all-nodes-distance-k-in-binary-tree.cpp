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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int,TreeNode*> p;//parent
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
               p[curr->left->val] = curr;
               q.push(curr->left);
            }
            if(curr->right){
                p[curr->right->val]=curr;
                q.push(curr->right);
            }
           
        }
        queue<TreeNode*> q1;
        q1.push(target);
        unordered_map<int,int> v;
        v[target->val]=1;
        while(k-- && !q1.empty()){
            int siz=q1.size();
            for(int i=0;i<siz;i++){
                auto curr=q1.front();
                q1.pop();
                if((curr->left!=NULL) && !v[curr->left->val]){
                    v[curr->left->val]=1;
                     q1.push(curr->left);
                }
                if((curr->right!=NULL) && !v[curr->right->val]){
                    v[curr->right->val]=1;
                    q1.push(curr->right);
                }
                TreeNode* parent=p[curr->val];
                if((parent!=NULL) && !v[parent->val]){
                   v[parent->val]=1;
                   q1.push(parent);
                }
            }
        }
        int s=q1.size();
        for(int i=0;i<s;i++){
            TreeNode* curr=q1.front();
            ans.push_back(curr->val);
            q1.pop();

        }

        return ans;
    }
};