class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int max=0,c=0,f;
        for(auto i=nums.begin();i!=nums.end();++i){
            f=count(nums.begin(),nums.end(),*i);
            if(f>max){
                max=f;
                
                c=1;
            }
            else if(f==max){
           
                c++;
            }
        }
        return c;
             
    }
};