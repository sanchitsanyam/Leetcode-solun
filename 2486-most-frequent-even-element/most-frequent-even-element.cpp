class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
        }
        int mostFrequent=-1;
        int highestFrequency=0;
        for(auto it=m.begin(); it!=m.end() ; it++){
            if(highestFrequency <= it->second){
                if(highestFrequency == it->second){
                    if(mostFrequent > it->first){
                        mostFrequent=it->first;
                    }
                }
                else{
                    mostFrequent=it->first;
                    highestFrequency=it->second;
                }
            }
        }
        
        return mostFrequent;
    }
};