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
class BSTIterator {
public:
    vector<int> Inord;
    int k;
    int n;
    void in(TreeNode* root){
        if(root==nullptr) return;
        if(root->left)in(root->left);
        Inord.push_back(root->val);
        if(root->right)in(root->right);

    }
    BSTIterator(TreeNode* root) {
        int x=root->val;
        in(root);
        n=Inord.size();
        k=-1;
    }
    
    int next() {
        ++k;
        if(k>n)return -1;
        else return Inord[k];
    }
    
    bool hasNext() {
        if(k+1<n)return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */