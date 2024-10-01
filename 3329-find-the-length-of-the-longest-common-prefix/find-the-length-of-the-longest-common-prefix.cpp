class Node{
    public:
    bool end_of_word;
    Node* children[10];
    Node(){
        end_of_word=false;
        for(int i=0;i<10;i++){
            children[i]=NULL;
        }
    }
};

class Trie{
    public:
        Node* root;
        Trie(){
            root=new Node();
        }
        void insert(string & word){
            Node* node=root;
            for(auto ch :word){
                if(node->children[ch-'0']==NULL){
                   node->children[ch-'0']= new Node();
                }
                node=node->children[ch-'0'];
            }
            node->end_of_word=true;
        }
        int lcp(string& str){
            Node* node=root;
            int len=0;
            for(auto ch :str){
                if(node->children[ch-'0']==NULL){
                   return len;
                }
                len++;
                node=node->children[ch-'0'];
            }
            return len;
            
        }

};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxlen=0;
        Trie trie;
        for(int i=0 ; i<arr1.size() ; i++){
            string s=to_string(arr1[i]);
            trie.insert(s);
        }
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            maxlen=max(trie.lcp(s),maxlen);

        }
        return maxlen;
    }
};