class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        unordered_map<int,int> m;
        int n=img1.size();
        for(int i1=0;i1<n;i1++){
            for(int j1=0;j1<n;j1++){
                if(img1[i1][j1]==0)continue;
                for(int i2=0;i2<n;i2++){
                    for(int j2=0;j2<n;j2++){
                        if(img2[i2][j2]==0)continue;
                        int dx=(i1-i2);
                        int dy=(j1-j2);
                        int k=dx*(2*n-1)+dy;
                        m[k]++;
                    }
                }
            }
        }
        int ans=0;
        for(auto it : m){
            ans = max(ans, it.second);
        }
        return ans;
    }
};