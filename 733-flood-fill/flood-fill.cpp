class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int c=image[sr][sc];
        image[sr][sc]=color;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        vector<vector<int>> dirn={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int x=v.first ,y=v.second;
            for(auto& u:dirn){
                int nx=x+u[0],ny=y+u[1];
                if(nx>=0 && nx<n && ny>=0 &&ny<m && vis[nx][ny]==0 &&image[nx][ny]==c){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
        return image;
    }
};