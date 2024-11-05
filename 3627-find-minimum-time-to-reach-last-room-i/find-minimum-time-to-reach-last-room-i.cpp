class Solution {
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size() ,m=moveTime[0].size();
        vector<vector<int>> dist(n ,vector<int>(m,INT_MAX));
        set<tuple<int ,int,int>>q ; q.insert({0,0,0});dist[0][0]=0;
        while(!q.empty()){
            auto [distance , x , y]=*q.begin();q.erase(*q.begin());
            for(int i=0;i<4 ;i++){
                int X=x+dx[i],Y=y+dy[i];
                if(X>=0 && Y>=0 && X<n && Y<m && dist[X][Y] > max(dist[x][y]+1, moveTime[X][Y]+1)){
                    q.erase({dist[X][Y],X ,Y});
                    dist[X][Y]=max(dist[x][y]+1, moveTime[X][Y]+1);
                    q.insert({dist[X][Y],X ,Y});
                }
            }
        }
        return dist[n-1][m-1];

    }
};