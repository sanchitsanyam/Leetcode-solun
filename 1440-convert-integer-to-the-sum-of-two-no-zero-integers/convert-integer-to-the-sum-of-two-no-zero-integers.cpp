class Solution {
public:
    bool check(int a){
        int t=10;
        while(a>=10){
            if(a%t == 0)return false;
            else{
                a=a/10;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            if(check(n-i) && check(i)){
                return {i,n-i};
            }
        }
        return {};
        
    }
};