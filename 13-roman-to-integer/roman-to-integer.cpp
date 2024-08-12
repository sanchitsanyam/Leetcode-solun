class Solution {
public:

    int romanToInt(string s) {
        unordered_map<char ,int>m;
        unordered_map<char ,int>O;
        O['I']=1;
        O['V']=5;
        O['X']=10;
        O['L']=50;
        O['C']=100;
        O['D']=500;
        O['M']=1000;
        int n=s.size();
        int num=O[s[n-1]];
  
        for(int i=n-2; i>=0 ;i--){
            m[s[i]]=m[s[i]]+1;
            if(O[s[i]]>=O[s[i+1]]){
                num+=O[s[i]];
            }
            else{
                num-=O[s[i]];
            }
        }
        return num;
        
    }
};