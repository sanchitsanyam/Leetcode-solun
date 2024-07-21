class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        
        int n=nums2.size();
        vector<int> nge(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
               nge[i]=st.top();
            }
            st.push(nums2[i]);
        }
        int n1=nums1.size();
        vector<int> ans(n1,-1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=nge[j];
                }
            }
        }
        return ans;
    }
};