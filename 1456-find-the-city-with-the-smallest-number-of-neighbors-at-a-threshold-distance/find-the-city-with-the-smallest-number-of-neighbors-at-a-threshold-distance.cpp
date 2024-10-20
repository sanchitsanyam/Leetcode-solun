class Solution {
    const int inf =1e9;
    vector<vector<int>> flyodWarshall(vector<vector<int>>& edges ,int n){
        vector<vector<int>> d(n, vector<int>(n,inf));
        for(int i=0;i<n;i++)d[i][i]=0;
        for(vector<int> e: edges){
            d[e[0]][e[1]]=e[2];
            d[e[1]][e[0]]=e[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        return d;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> d=flyodWarshall(edges,n);
        int ans=-1 , minCount=inf;
        for(int src = 0 ; src < n ; src++){
            int curCount=0;
            for(int des=0;des<n;++des){
                if(d[src][des] <=distanceThreshold){
                    curCount+=1;
                }
            }
            if(curCount <= minCount){
               minCount=curCount;
               ans=src;
            }   

        }
        return ans;
    }
};