// class Node{
//     public:
//         bool end_of_word;
//         Node* children[26];
//         Node(){
//             end_of_word=false;
//             for(int i=0;i<26;i++){
//                 children[i]=NULL;
//             }
//         }
// };
// class Trie{
//     public:
//         Node* root;
//         Trie(){
//             root= new Node();
//         } 
//         void insert(string &word){
//             Node* node=root;
//             for(auto ch: word){
//                 if(node->children[ch-'a']==NULL){
//                    node->children[ch-'a']= new Node; 
//                 }
//                 node=node->children[ch-'a'];
//             }
//             node->end_of_word=true;
//         }
//         Node* search(string& prefix){
//             Node* node=root;
//             for(auto ch:prefix){
//                 if(node->children[ch-'a']==NULL)return NULL;
//                 node=node->children[ch-'a'];
//             }
//             return Node;
//         }
//         void dfs(Node* node, vector<string>&strings ,string &str){
//             if(node==NULL || strings.size()==3){
//                 return;
//             }
//             if(node->end_of_word){
//                 strings.push_back(str);
//             }
//             for(int i=0;i<26 ;i++){
//                 if(node->children[i]!=NULL){
//                     str.push_back('a'+i);
//                     dfs(node->children[i],string,str)
//                 }
//             }
//         }
// }
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> result;
        int start ,bstart=0 ,n=products.size();
        string prefix="";
        for(auto& c: searchWord){
            prefix+=c;
            start=lower_bound(products.begin()+bstart , products.end(),prefix)-products.begin();
            result.push_back({});
            for(int i=start ;i<min(start+3 ,n) && (!products[i].compare(0,prefix.length(),prefix));i++){
                result.back().push_back(products[i]);
            }
            bstart=start;
        }    
        return result;


    }
    
};