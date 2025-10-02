class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int r=numExchange;
        while(numBottles >=r){
            numBottles-=(r-1);
            r++;
            ans++;
        }
        return ans;
    }
};