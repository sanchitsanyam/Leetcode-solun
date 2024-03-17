class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int t=1;
        int n=nums.size();
        if(n%3!=0){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]<=k){
                continue;
            }
            else{
                t=0;
            }
        }
        if(t==0){
            return ans;
        }
        else{
            int j;
            vector<int> res(3);
            for(int i=0;i<n;i++){
                if(i%3==0){
                    j=0;
                   res[0]=nums[i];
                }
                if(i%3==1){
                    j=1;
                   res[1]=nums[i]; 
                }
                if(i%3==2){
                    j=2;
                   res[2]=nums[i]; 
                }
                if(j==2){
                    ans.push_back(res);
                }
            }
            return ans; 
        }
    }
};