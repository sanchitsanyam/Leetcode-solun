class Solution {
public:
    int mySqrt(int x) {
        int  ans=0;
        for(long i=0;i<=x;i++){
            if(i*i<=x){
                ans=i;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};