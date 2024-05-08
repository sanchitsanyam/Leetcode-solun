class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums1(2*n,-1);
        stack<int> st;
        vector<int> ans(2*n,-1);
        for(int i=0;i<n;i++){
            nums1[i]=nums[i];
            nums1[i+n]=nums[i];
        }
        for(int i=2*n-1;i>=0;i--){
            if(st.empty()){

               st.push(nums1[i]);
            }
            while(!st.empty() && nums1[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
               ans[i]=st.top();
            }
            st.push(nums1[i]);

        }
        vector<int> ansf(n,-1);
        for(int i=0;i<n;i++){
            ansf[i]=ans[i];
        }
        return ansf;
    }
    
};