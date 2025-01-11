class Solution {
public:
    vector<string> ans;
    int target;
    void help(int i, long prev , long curr , string& num ,string expr){
        if(i==num.size()){
            if(curr==target){
                ans.push_back(expr);
            }
            return;
        }
        for(int j=i;j<num.size();j++){
            string part=num.substr(i,j-i+1);
            long val=stol(part);
            if(part.size()>1 && part[0]=='0' )break;
            if(i==0){
                help(j+1,val,val,num ,expr+part);
            }
            else{
                help(j+1,val,curr+val,num,expr+"+"+part);
                help(j+1,-val,curr-val,num,expr+"-"+part);
                help(j+1,prev*val,curr-prev+prev*val,num ,expr+"*"+part);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        this->target=target;
        if(num.empty())return ans;
        help(0,0,0,num,"");
        return ans;
    }
};