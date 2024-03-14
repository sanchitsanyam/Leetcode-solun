class Solution {
public:
    //competitor function
    bool static sorted(const vector<int>&v1,const vector<int>&v2){
        if(v1[1]==v2[1]){
            return v1[0]>v2[0];
        }
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),sorted);  
        int ans=0;
        for(auto it:boxTypes){
            int x=min(truckSize,it[0]);
            ans+=it[1]*x;
            truckSize-=x;
            if(truckSize==0){
                break;
            }
        }
        return ans;
    }
};