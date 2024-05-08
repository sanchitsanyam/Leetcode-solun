class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       
        stack<int> cat;
        int n=nums2.size();
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--){
            if(cat.empty()){
                ans[i]=-1;
                cat.push(nums2[i]);
            }
            while((!cat.empty())&&(nums2[i]>=cat.top())){
                cat.pop();
            }
            if(!cat.empty()){
               ans[i]=cat.top();
            }
            cat.push(nums2[i]);
        }
        int n1=nums1.size();
        vector<int> finalans(n1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    finalans[i]=ans[j];
                }
            }
        }
        return finalans;

    }
};