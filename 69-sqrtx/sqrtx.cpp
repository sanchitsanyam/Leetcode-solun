class Solution {
public:
    int mySqrt(int x) {
        if(x==1)return 1;
        if(x==0)return 0;
        int s=0,e=x/2;
        int  ans=0;
        while(s<=e){
           long mid=s+(e-s)/2;
           if(mid*mid==x) return mid;
           else if(mid*mid<x){
               ans=mid;
               s=mid+1;
           }
           else{
               e=mid-1;
           }
        }
        return ans;
        
    }
};