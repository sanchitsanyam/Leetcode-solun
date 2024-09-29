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
class Trie {
public:
       Node* root;
    Trie() {
       root=new Node(); 
    }
    
    void insert(string word) {
        Node* node=root;
        for(auto ch:word){
            if(node->children[ch-'a']==NULL){
                node->children[ch-'a']=new Node();
            }
            node=node->children[ch-'a'];
        }
        node->end_of_word=true; 
    }
    
    bool search(string word) {
        Node* node= root;
        for(auto ch: word){
            if(node->children[ch-'a']==NULL)return false;
            node=node->children[ch-'a'];
        }
        return node->end_of_word;
        
    }
    
    bool startsWith(string prefix) {
        Node* node= root;
        for(auto ch: prefix){
            if(node->children[ch-'a']==NULL)return false;
            node=node->children[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */