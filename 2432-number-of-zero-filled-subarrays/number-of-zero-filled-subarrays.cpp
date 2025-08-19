class Solution {
public:
    long long cl(long long n){
       
        long long c=n*(n+1)*(0.5);
        return c;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        vector<long long> Ct(n+1,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int cnt=0;
                while(i<n && nums[i]==0){
                    cnt++;
                    i++;
                }
                Ct[cnt]++;
            }
        }
        for(int i=0;i<=n;i++){
            sum+=(long long )cl(i)*Ct[i];
            //cout<<Ct[i]<<" "<<cl(i)<<endl;
        }
        return sum;
    }
};