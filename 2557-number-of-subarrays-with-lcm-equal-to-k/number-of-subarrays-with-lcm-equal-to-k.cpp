class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int lcm =nums[i];
            if(lcm==k)cnt++;
            for(int j = i+1; j<n ; j++){
                int gcd = __gcd(nums[j],lcm);
                lcm=(lcm*nums[j])/gcd;
                if(lcm>k)break;
                if(lcm==k)cnt++;
            }
        }
        return cnt;
    }
};