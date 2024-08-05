class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it = m.begin(); it != m.end() ; ++it){
            int r=it->second;
            c += r*(r-1)*0.5;
        }
        return c;
    }
};