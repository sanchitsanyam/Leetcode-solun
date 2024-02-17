class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        vector<int> pop(3001);
        for(int i=0;i<n;i++){
            pop[logs[i][0]]++;
            pop[logs[i][1]]--;
            
        }
        int max=0;
        int max_yr;
        for(int i=1950;i<2051;i++){
            pop[i]+=pop[i-1];
            if(max<pop[i]){
                max=pop[i];
                max_yr=i;
            }
        }
        return max_yr;
        
    }
};