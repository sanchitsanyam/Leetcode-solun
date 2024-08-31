class Solution {
public:
    bool static comp(vector<int>&v1 , vector<int>&v2){
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end() , comp );
        int n=points.size();
        int cnt=1;
        int tg=points[0][1];
       
        for(int i=0;i<n;i++){
            if(tg>=points[i][0]){
                
                
            }
            else{
                tg=points[i][1];
                cnt++;
            }
            
        }
        return cnt;
    }
};