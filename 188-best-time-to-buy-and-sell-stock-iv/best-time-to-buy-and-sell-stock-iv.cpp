class Solution {
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
public:
    int maxProfit(int k1, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(2*k1+1,0));
        for(int j=0;j<=1;j++){
            for(int k=0;k<=2*k1;k++){
                prev[j][k]=0;
            }
        }
        for(int j=0;j<=1;j++){
            prev[j][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int>(2*k1+1,0));
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2*k1;k++){
                    int opn1,opn2;
                    if(j==0){
                        opn1=-prices[i]+prev[1][k-1];
                        opn2=prev[j][k];
                    }
                    else{
                        opn1=prices[i]+prev[0][k-1];
                        opn2=prev[j][k];
                    }
                    curr[j][k]=max(opn1,opn2);
                }
                
            }
            prev=curr;
        }
        return prev[0][2*k1];
    }
};