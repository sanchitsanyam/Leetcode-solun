class Solution {
public:
    int numEnclaves(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dirn={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1)&& g[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int x=v.first , y=v.second;
            for(auto& u:dirn){
                int nx=x+u[0],ny=y+u[1];
                if(nx>=0 && ny>=0 && nx<n && ny<m && vis[nx][ny]==0 && g[nx][ny]==1){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && vis[i][j]==0){
                    c++;
                }
            }
        }
        return c;

    }
};