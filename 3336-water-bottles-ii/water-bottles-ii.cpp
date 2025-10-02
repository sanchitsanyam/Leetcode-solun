class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int x = numBottles;
        int y = numExchange;
        int ans=x;
        int z=0;
        while(x>0){
            x=x-y;
            z++;
            y++; 
            if(x<y){
                ans+=z;
                x+=z;
                z=0;
            }    
    
        }
        return ans-1;
        
    }
};