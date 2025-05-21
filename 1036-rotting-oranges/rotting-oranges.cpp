// Multi-source BFS`
class Solution {
public:
    vector<int> src;
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>& grid1=grid;
        queue<pair<int,int>> q;
        int cntFresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==2){
                    q.push({i,j});
                }
                if(grid1[i][j]==1)cntFresh++;
            }
        }
        if(cntFresh==0)return 0;
        vector<vector<int>> dirn={{0,-1},{1,0},{0,1},{-1,0}};
        int time=-1;
        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                auto [x,y]=q.front();
                q.pop();
                for(auto& p : dirn){
                    int nx=p[0],ny=p[1];
                    int i=x+nx;
                    int j=y+ny;
                    if(i>=0 && i<m && j>=0 && j<n && grid1[i][j]==1){
                        grid[i][j]=2;
                        q.push({i,j});
                        cntFresh--;
                    }
                }
            }
            time++;
        }
        if(cntFresh==0)return time;
        else return -1;

    }
};