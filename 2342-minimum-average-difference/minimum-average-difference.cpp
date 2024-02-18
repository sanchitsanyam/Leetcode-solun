class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long n=nums.size();
        if(n==1){
            return 0;
        }
        long long s=0;
        long long e=n-1;
        long long   m=0;
        vector<long long> prfx;
        
        long long sum=0;
        for(long long i=0;i<n;i++){
            sum+=nums[i];
            prfx.push_back(sum);
        }
        long long min=INT_MAX;
        long long k,ind;
        for(m=n-2;m>=0;m--){
            k=abs((prfx[m]/(m+1))-((sum-prfx[m])/(n-m-1)));
            if(k<=min){
                min=k;
                ind=m;
            }
        }
        long long  t=abs(sum/n);
        if(min>t){
            return n-1;
        }
        return ind;


    }
};