class Solution {    
public:
    long atoi(string s ,int sign , int i ,long result){
        if(sign*result>=INT_MAX){
            return INT_MAX;
        }
        if(sign*result<=INT_MIN){
            return INT_MIN;
        }
        if(i>s.size() || s[i]<'0' ||s[i]>'9'){
            return sign*result;
        }
        result=atoi(s,sign,i+1,result*10+(s[i]-'0'));
        return result;

    }
    int myAtoi(string s) {
        int n=s.length(),sign=1;
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(s[i]=='-')sign=-1,i++;
        else if(s[i]=='+')i++;
        return atoi(s,sign,i,0);
        
    }
};