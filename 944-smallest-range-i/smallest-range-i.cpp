class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n=nums.size();
        int max=INT_MIN;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]>max){
                max=nums[i];
            }
            if(nums[i]<min){
                min=nums[i];
            }
        }
        int p;
        if((max-min)%2==0){
           p=(max-min)/2; 
            if(k>=p){
              return (max-p)-(min+p);
            }
            else{
                p=k;
                return (max-p)-(min+p);
            }
        }
        else{
           p=(int)((max-min)/2); 
           if(k>=p+1){
              return (max-p)-(min+p+1);
            }
            else{
                p=k;
                return (max-p)-(min+p);
            }
        }
        
        

    }
};