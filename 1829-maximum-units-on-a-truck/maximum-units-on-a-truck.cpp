class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
		 /*custom sort (in increasing order of 
		 numberOfUnitsPerBox as we have to return  
		 maximum total number of units )*/
        int ans=0;
        for(auto it:boxTypes){
            int x=min(truckSize,it[0]);
            ans+=it[1]*x; //adding units in ans
            truckSize-=x; //reduce the capacity
            if(truckSize==0){ // capacity is full
                break;
            }
        }
        return ans;
    }
};