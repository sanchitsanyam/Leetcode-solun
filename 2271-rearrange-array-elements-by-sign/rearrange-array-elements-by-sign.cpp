class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        int t=nums.size();
        for(int i=0;i<t;i++){
            if(nums[i]>=0){
                p.push_back(nums[i]);
            }
            else{
                n.push_back(nums[i]);
            }
        }
        vector<int> final;
        int pt=p.size();
        int nt=n.size();
        int j=0,k=0;
        int i=0;
        while(i<t && j<pt && k<nt){
            if(i%2==0){
                final.push_back(p[j]);
                j++;
            }
            else{
                final.push_back(n[k]);
                k++;
            }
            i++; 
        }
        while(j<pt){
            final.push_back(p[j]);
            j++;
        }
        while(k<nt){
           final.push_back(n[k]); 
           k++;
        }
        return final;

    }
};