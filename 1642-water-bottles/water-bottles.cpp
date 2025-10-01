class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int x=numBottles;
        int y=numExchange;
        int ans=x;
        while(x>0){
            ans+=(x/y);
            x=(x/y)+(x%y);
            if(x<y)break;
        }
        return ans;
    }
};