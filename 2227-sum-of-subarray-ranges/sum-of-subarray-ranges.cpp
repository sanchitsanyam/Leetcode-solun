class Solution {
public:
    long long subArrayMinm(vector<int>& nums){
        int n=nums.size();
        vector<int> nse(n),pse(n);
        for(int i=0; i<n; i++){
            nse[i]=n-i-1;
            pse[i]=i;
        }
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && nums[s1.top()]>nums[i]){
                nse[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && nums[s2.top()]>=nums[i]){
                pse[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        long long sum=0;
        for(int i=0 ; i<n; i++){
            sum+=(long long)nums[i]*(long long)(nse[i]+1)*(long long)(pse[i]+1);
        }
        return sum;
    }
    long long subArrayMaxm(vector<int>& nums){
        int n=nums.size();
        vector<int> nge(n),pge(n);
        for(int i=0; i<n; i++){
            nge[i]=n-i-1;
            pge[i]=i;
        }
        stack<int> s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() && nums[s1.top()]<nums[i]){
                nge[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && nums[s2.top()]<=nums[i]){
                pge[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        long long sum=0;
        for(int i=0 ; i<n; i++){
            sum+=(long long)nums[i]*(long long)(nge[i]+1)*(long long)(pge[i]+1);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long MaxSum=subArrayMaxm(nums);
        cout<<MaxSum<<endl;
        long long MinSum=subArrayMinm(nums);
        cout<<MinSum<<endl;
        return MaxSum-MinSum;
    }
};