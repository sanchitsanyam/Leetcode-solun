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
    TreeNode* bstFromPreorder(vector<int>& preorder){
        if(preorder.size()==0)return nullptr;
        int x=preorder[0];
        TreeNode* curr=new TreeNode(preorder[0]);
        int c=1;
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]<x){
                c++;
            }
        }
        vector<int> leftsub(preorder.begin()+1,preorder.begin()+c);
        vector<int> rightsub(preorder.begin()+c,preorder.end());
        curr->left=bstFromPreorder(leftsub);
        curr->right=bstFromPreorder(rightsub);
        return curr;
    }
};