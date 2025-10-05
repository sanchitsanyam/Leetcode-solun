class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        if(n==0)return {};
        if(m==0)return {};
        vector<vector<int>> dirn={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>> p(n,vector<int>(m,0));
        vector<vector<int>> a(n,vector<int>(m,0));
        queue<pair<int,int>> q;
       
        for(int j=0;j<m;j++){
            q.push({0,j});
            p[0][j]=1;
        }
        for(int i=0;i<n;i++){
            q.push({i,0});
            p[i][0]=1;
        }
        while(!q.empty()){
            auto k=q.front();
            q.pop();
            int x=k.first;
            int y=k.second;
            for(auto& t:dirn){
                int x1=x+t[0];
                int y1=y+t[1];
                if(x1>=0 && x1<n){
                    if(y1>=0 && y1<m){
                        if((!p[x1][y1]) && (h[x1][y1]>=h[x][y])){
                            q.push({x1,y1});
                            p[x1][y1]=1;
                        }
                    }
                }
            }
        }


        queue<pair<int,int>> q1;
       
        for(int j=0;j<m;j++){
            q1.push({n-1,j});
            a[n-1][j]=1;
        }
        for(int i=0;i<n;i++){
            q1.push({i,m-1});
            a[i][m-1]=1;
        }
        while(!q1.empty()){
            auto k=q1.front();
            q1.pop();
            int x=k.first;
            int y=k.second;
            for(auto& t:dirn){
                int x1=x+t[0];
                int y1=y+t[1];
                if(x1>=0 && x1<n){
                    if(y1>=0 && y1<m){
                        if((!a[x1][y1]) && (h[x1][y1]>=h[x][y])){
                            q1.push({x1,y1});
                            a[x1][y1]=1;
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1 && p[i][j]==1){
                   ans.push_back({i,j});
                }         
            }
        }
        return ans;
        
    }
};