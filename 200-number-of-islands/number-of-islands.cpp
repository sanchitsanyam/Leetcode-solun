class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        vector<vector<int>> dirn={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto v=q.front();
                        q.pop();
                        int x=v.first,y=v.second;
                        for(auto& u:dirn){
                            int nx=x+u[0];
                            int ny=y+u[1];
                            if(nx>=0 &&ny>=0 && nx<n &&ny<m && vis[nx][ny]==0 && grid[nx][ny]=='1'){
                                q.push({nx,ny});
                                vis[nx][ny]=1;
                            }
                        }
                    }
                    t++;
                }
            }
        }
        return t;
        
    }
};