class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        long long res=0,curr=0;
        // Start at coins[i][0]
        for(long long i=0,j=0;i<n;i++){
            //including full interval
            while(j<n && coins[j][1]<=coins[i][0]+k-1){
                curr+=1L*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            //including partial intervals
            if(j<n){
                long long part=1L*max(0,coins[i][0]+k-1-coins[j][0]+1)*coins[j][2];
                res=max(res,curr+part);
            }
            curr-=1L*(coins[i][1]-coins[i][0]+1)*coins[i][2];
        }
        curr=0;
        for(long long i=0,j=0;i<n;i++){
            curr+=1L*(coins[i][1]-coins[i][0]+1)*coins[i][2];
            //removing full intervlas 
            while(coins[j][1]<coins[i][1]-k+1){
                curr-=1L*(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            //removing partial interval;
            long long part=1L*max(0,coins[i][1]-k-coins[j][0]+1)*coins[j][2];
            res=max(res,curr-part);
        }
        return res;


    }
};