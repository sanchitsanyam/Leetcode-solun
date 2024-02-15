class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> left_sum;
        left_sum.push_back(0);
        int n=nums.size();
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=nums[i-1];
            left_sum.push_back(sum);
        }
        vector<int> right_sum;
        right_sum.push_back(0);
        sum=0;
        for(int i=n-2;i>=0;i--){
            sum+=nums[i+1];
            right_sum.push_back(sum);
        }
        vector<int> g;
        for(int i=0;i<n;i++){
            g.push_back(abs(left_sum[i]-right_sum[n-i-1]));
        }
        return g;
        

    }
};