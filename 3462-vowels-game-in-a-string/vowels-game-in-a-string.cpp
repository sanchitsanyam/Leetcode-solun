class Solution {
public:
    bool doesAliceWin(string s) {
        int v=0;
        for(char & c: s){
            if(c=='a' || c=='e' || c=='i' || c=='o'||c=='u')v++;
        }
        if(v==0)return false;
        else return true;
    }
};