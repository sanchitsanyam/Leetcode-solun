class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        
        vector<int> p(n+1,1);
        p[0]=0;
        p[1]=0;
        for(int i=2; i*i<=n ; i++){
            if(p[i]){
                for(int j=2*i ; j<=n ; j+=i){
                     p[j]=0;
                }
            }
        }
        vector<vector<int>> ans;
        for(int j=2;j<=n ;j++){
            if(p[j]){
                if(p[n-j]){
                    if(j<=n-j){
                        ans.push_back({j,n-j});
                    }
                }
            }
        }
        return ans;
;    }
};