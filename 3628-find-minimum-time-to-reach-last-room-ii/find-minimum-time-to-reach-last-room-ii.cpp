
class Solution {
    const int dx[4]={1,-1,0,0};
    const int dy[4]={0,0,-1,1};
    
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n= moveTime.size();
        int m= moveTime[0].size();
        vector<vector<int>> dis(n+1,vector<int>(m+1,INT_MAX));
        set<tuple<int ,int,int, int>> q; 
        q.insert({0,0,0 ,0});
        dis[0][0]=0;
        while(!q.empty()){
            auto [distance ,x,y ,j]=*q.begin();
            q.erase(*q.begin());
            for(int i=0;i<4;i++){
                int X=x+dx[i],Y=y+dy[i];
                
                if(X>=0 && Y>=0 && X<n && Y < m && dis[X][Y] >( (j%2==0)?max(dis[x][y]+1,moveTime[X][Y]+1):max(dis[x][y]+2,moveTime[X][Y]+2))){
                    q.erase({dis[X][Y], X, Y, j});
                    dis[X][Y]=(j%2==0)?max(dis[x][y]+1,moveTime[X][Y]+1):max(dis[x][y]+2,moveTime[X][Y]+2);
                    q.insert({dis[X][Y],  X, Y, j+1});
                }
            }
        }
        return dis[n-1][m-1];

    }
};