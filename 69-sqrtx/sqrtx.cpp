class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int r=x;
        int ans;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid<=x){ 
                ans=mid;
               l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};