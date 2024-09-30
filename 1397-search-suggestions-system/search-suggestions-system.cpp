class Node{
    public:
        bool end_of_word;
        Node* children[26];
        Node(){
            end_of_word=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
class Trie{
    public:
        Node* root;
        Trie(){
            root= new Node();
        } 
        void insert(string &word){
            Node* node=root;
            for(auto ch: word){
                if(node->children[ch-'a']==NULL){
                   node->children[ch-'a']= new Node; 
                }
                node=node->children[ch-'a'];
            }
            node->end_of_word=true;
        }
        Node* search(string& prefix){
            Node* node=root;
            for(auto ch:prefix){
                if(node->children[ch-'a']==NULL)return NULL;
                node=node->children[ch-'a'];
            }
            return node;
        }
        void dfs(Node* node ,vector<string>&strings ,string& str){
            if(node==NULL || strings.size()==3)return;
            if(node->end_of_word)strings.push_back(str);
            for(int i=0;  i<26 ;i++){
                if(node->children[i]!=NULL){
                    str.push_back('a'+i);
                    dfs(node->children[i],strings,str);
                    str.pop_back();
                }
            }
        }
        
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Trie trie;
        for(auto str:products){
           trie.insert(str);
        }
        string prefix;
        for(auto ch: searchWord){
            prefix +=ch;
            Node* node=trie.search(prefix);
            vector<string> strings;
            trie.dfs(node , strings , prefix);
            ans.push_back(strings);
        }
        return ans;


    }
    
};