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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root=buildTreehelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;

    }
    TreeNode* buildTreehelper(vector<int>& preorder, int prestart,int preend,
    vector<int>& inorder,int instart,int inend, map<int,int>& inMap){
        if(preend<prestart || inend<instart){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=inMap[root->val];
        int numsLeft=inroot-instart;
        //left subtree
        root->left=buildTreehelper(preorder,prestart+1,prestart+numsLeft,inorder,instart,inroot-1,inMap);
        //right subtree
        root->right=buildTreehelper(preorder,prestart+numsLeft+1,preend,inorder,inroot+1,inend,inMap);

        return root;
    }
};