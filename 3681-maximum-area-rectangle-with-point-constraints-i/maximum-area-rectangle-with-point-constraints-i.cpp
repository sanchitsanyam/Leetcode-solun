class Solution {
public:
    int area(vector<vector<int>>& point){
        vector<int> bl ,br , tl ,tr;
        bl=point[0],tl=point[1],br=point[2],tr=point[3];
        if(bl[0]!=tl[0] || br[0]!=tr[0])return -1;
        if(bl[1]!=br[1] || tl[1]!=tr[1])return -1;
        return(abs(bl[0]-br[0])*abs(tl[1]-bl[1]));
    }
    bool hasbw(vector<vector<int>>&points ,vector<vector<int>>& vals ){
        int n=points.size();
        vector<int> bl,br,tl,tr;
        bl=vals[0],tl=vals[1],br=vals[2],tr=vals[3];
        for(int i = 0; i < n; i++){
            if(bl==points[i]|| br==points[i] ||tl==points[i] || tr==points[i])continue;
            int x=points[i][0] ,y=points[i][1];
            if(x >= bl[0] && x <= br[0] && y>=bl[1] &&y<=tl[1])return true;
        }
        return false;
    }
    int maxRectangleArea(vector<vector<int>>& points) {
        int ans=-1;
        int n=points.size();
        if(n<4)return -1;
        for(int i=0;i<n;i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        vector<vector<int>> vals={points[i],points[j],points[k],points[l]};
                        sort(vals.begin(),vals.end());
                        if(area(vals)==-1)continue;
                        if(hasbw(points,vals))continue;
                        ans=max(ans ,area(vals));

                    }
                }
            }
        }
        return ans;

    }
};