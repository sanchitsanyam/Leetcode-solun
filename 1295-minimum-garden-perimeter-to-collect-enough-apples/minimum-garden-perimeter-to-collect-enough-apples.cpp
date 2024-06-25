class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        int ans=-1;
        for(long long i=0;i<INT_MAX;i++){
            if((long long)(i*(i+1)*(2*i+1)*2)>= neededApples){
                ans=8*i;
                break;
            }
        }
        return ans;
    }
};