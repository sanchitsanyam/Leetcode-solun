class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int end =intervals[0][1];
        for(int j=1 ; j<intervals.size() ; j++){
            if(intervals[j][0]>=end){
                end=intervals[j][1]  ;
            }
            
            else{
              cnt++;
              end=min(end,intervals[j][1]);
            } 
        }
        return cnt;

    }
};