class Solution {
public:
    const int N=1e5;
    const int mod=1e9+7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        vector<long long> count(N+1,0);
        vector<long long> sum(N+1 ,0);
        int n=nums.size();
        for(long long i=0;i<n;i++){
            long long x=nums[i]%mod;
            long long t=((x-1)>=0)?count[x-1]:0;
            t=t%mod;
            long long count_NEXT=(x+1<=N)?count[x+1]:0;
            count_NEXT=count_NEXT%mod;
            long long sum_NEXT=(x+1<=N)?sum[x+1]:0;
            sum_NEXT=sum_NEXT%mod;
            long long sum_prev=(x-1>=0)?sum[x-1]:0;
            sum_prev=sum_prev%mod;
            count[x]+=1+t+count_NEXT;
            sum[x]=(sum[x]%mod+(x+((t)*x)%mod+sum_prev + (count_NEXT*x)%mod+ sum_NEXT)%mod)%mod;
            
        }
       
        long long Tsum=0;
        for(int i=0;i<=N;i++){
            Tsum=(Tsum%mod+sum[i]%mod)%mod;
        }
        
        long long ans=Tsum%mod;
        return ans;
    }
};