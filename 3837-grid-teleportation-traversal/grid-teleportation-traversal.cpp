class Solution {
public:
    const vector<vector<int>> dirn={{-1,0},{0,1},{0,-1},{1,0}};
    int solve(int sx, int sy ,vector<string>& matrix, unordered_map<char,vector<pair<int,int>>>& mp){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[sx][sy]=0;
        vector<bool> used(26,false);
        deque<pair<int,int>>dq;
        dq.emplace_back(sx,sy);
        while(!dq.empty()){
            auto [x,y]=dq.front();
            dq.pop_front();
            int d=dist[x][y];
            char c=matrix[x][y];
           
            if(c>='A' && c<='Z' && !used[c-'A']){
                used[c-'A']=true;
                for(const auto & p: mp[c]){
                    int nx=p.first,ny=p.second;
                    if(dist[nx][ny] >d){
                        dist[nx][ny]=d;
                        dq.emplace_front(nx,ny);
                    }
                }
            }
            for(auto & v : dirn){
                int nx=x+v[0],ny=y+v[1];
                if(nx<0|| ny<0 ||nx>=m || ny>=n)continue;
                if(matrix[nx][ny]=='#')continue;
                if(dist[nx][ny] > d+1){
                    dist[nx][ny]=d+1;
                    dq.emplace_back(nx,ny);
                }

            }
        }
        return (dist[m-1][n-1]==(1e9))? -1:dist[m-1][n-1];
    }
    int minMoves(vector<string>& matrix) {
        int m=matrix.size();
        if(m==0)return -1;
        int n=matrix[0].size();
        unordered_map<char,vector<pair<int,int>>> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char c=matrix[i][j];
                if(c>='A' && c<='Z'){
                    mp[c].emplace_back(i,j);
                }
            }
        }
        return solve(0,0,matrix,mp);
        
    }
};