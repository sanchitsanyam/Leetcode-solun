/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        queue<TreeNode*> q;
        if(root==nullptr)return s;
        q.push(root);
        s+= to_string(root->val);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                s+=","+ to_string(curr->left->val);
            }
            else{
                s+=",null";
            }
            if(curr->right){
                q.push(curr->right);
                s+=","+ to_string(curr->right->val);
            }
            else{
                s+=",null";
            }

        }
        return s;

        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int j=0;
        vector<string> data1;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            data1.push_back(token);
        }
        TreeNode* root=nullptr;
        int n=data1.size();
        if(j<n){
            if(data1[j]!="null")root= new TreeNode(stoi(data1[0]));
            else return root;
            j++;
        }    
        else return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(j<n){
                    if(data1[j]!="null")curr->left=new TreeNode(stoi(data1[j]));
                    else curr->left=nullptr;
                    j++;
                    if(curr->left)q.push(curr->left);
                }
                else return root;
                if(j<n){
                    if(data1[j]!="null")curr->right=new TreeNode(stoi(data1[j]));
                    else curr->right=nullptr;
                    j++;
                    if(curr->right)q.push(curr->right);
                }
                else return root;
            }        
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));