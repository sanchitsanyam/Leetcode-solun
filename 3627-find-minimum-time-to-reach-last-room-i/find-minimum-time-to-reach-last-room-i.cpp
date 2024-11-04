
class Solution {
    int n ,m;
    vector<vector<int>> memo;
    int dfs(vector<vector<int>>& moveTime ,int i ,int j , int time){
        if(i==n-1 && j==m-1)return time;
        if(memo[i][j]<=time)return INT_MAX;
        memo[i][j]=time;
        int mintime=INT_MAX;
        //up
        if(i>0){
            int newTime=max(time , moveTime[i-1][j]);
            mintime=min(mintime,dfs(moveTime,i-1,j,newTime+1));
        }
        //down
        if(i<n-1){
            int newTime=max(time , moveTime[i+1][j]);
            mintime=min(mintime,dfs(moveTime,i+1,j,newTime+1));
        }
        //left
        if(j>0){
            int newTime=max(time , moveTime[i][j-1]);
            mintime=min(mintime,dfs(moveTime,i,j-1,newTime+1));
        }
        //right
        if(j<m-1){
            int newTime=max(time , moveTime[i][j+1]);
            mintime=min(mintime,dfs(moveTime,i,j+1,newTime+1));
        }
        return mintime;

    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n=moveTime.size();
        m=moveTime[0].size();
        memo.assign(n,vector<int>(m,INT_MAX));
        return dfs(moveTime, 0, 0, 0);
    }
};