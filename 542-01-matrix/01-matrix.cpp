class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m));
        vector<vector<int>> v(n ,vector<int>(m,0));
        queue<pair<int,int>> q;
        vector<vector<int>> dirn={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
                else ans[i][j]=INT_MAX;
            }
        }
        int t=1;
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                auto u=q.front();
                q.pop();
                int x=u.first ,y=u.second;
                for(auto& v: dirn){
                    int nx=x+v[0],ny=y+v[1];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && ans[nx][ny]>t){
                        ans[nx][ny]=t;
                        q.push({nx,ny});
                    }
                }
            }
            t++;
        }
        return ans;
        
    }
};