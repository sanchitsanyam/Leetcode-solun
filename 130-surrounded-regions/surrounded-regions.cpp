class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirn={{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n ; i++){
            for(int j=0 ; j<m ;j++){
                if((i==0||j==0||i==n-1||j==m-1)&&b[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                }    
            }
        }
        while(!q.empty()){
            auto v=q.front();
            int x=v.first,y=v.second;
            q.pop();
            for(auto & u:dirn){
                int nx=x+u[0],ny=y+u[1];
                if(nx>0 && ny>0 && nx<(n-1) && ny<(m-1) && vis[nx][ny]==0 && b[nx][ny]=='O' ) {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && b[i][j]=='O'){
                    b[i][j]='X';
                }
            }
        }
        
        
    }
};