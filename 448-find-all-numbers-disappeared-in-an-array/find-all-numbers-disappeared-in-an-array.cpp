class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> g1;
        vector<int> g2;
        for(int i=0;i<nums.size();i++){
            g1.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(g1[nums[i]-1]>0){
                g1[nums[i]-1]*=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(g1[i]>0){
                g2.push_back(i+1);
            }
        }
      
        return g2;
        

       

    }
};