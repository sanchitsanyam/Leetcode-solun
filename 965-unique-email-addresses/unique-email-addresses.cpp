class Solution {
private:
    void filter(const string& email , string& s){
        bool localName = true;
        for( int i=0 ;i<email.size() ;i++){
            if(email[i] == '+' && localName){
                while(email[i]!='@'){
                     i++;
                }
                localName=false;
            }
            else if(email[i]=='.' && localName){
                continue;
            }
            else if(email[i]=='@'){
                localName=false;
                
            }
            s+=email[i];
           
            
        }
        
    }
public:    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> S; 
       for(auto& email :emails){
          string s="";
          filter(email ,s);
          S.insert(s);
       }
       return S.size();
    }
};