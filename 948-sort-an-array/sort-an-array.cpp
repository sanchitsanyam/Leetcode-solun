class Solution {
public:
    vector<int> merge2SortedArrays(vector<int>&left,vector<int>& right){
        int lftsz=left.size();
        int rtsz=right.size();
        int i=0,j=0;
        vector<int> ans;
        while(i<lftsz && j<rtsz){
            if(left[i]<=right[j]){
                ans.push_back(left[i]);
                i++;
            }
            else{
                ans.push_back(right[j]);
                j++;
            }
        }
        while(i<lftsz){
            ans.push_back(left[i]);
            i++;
        }
        while(j<rtsz){
            ans.push_back(right[j]);
            j++;
        }
        return ans;
       
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums;
        }
        vector<int> left(nums.begin(),nums.begin()+n/2);
        vector<int> right(nums.begin()+n/2,nums.end());
        left=sortArray(left);
        right=sortArray(right);
        return merge2SortedArrays(left,right);
    }
};