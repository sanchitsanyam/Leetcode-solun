class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0;
        int r=n-1;
        for(int i=0;i<n;i++){
            int x=numbers[i];
            int s=i+1,e=n-1;
            while(s<=e){
                int m=s+(e-s)/2;
                if(x+numbers[m]==target){
                   return{i+1,m+1}; 
                }
                else if(x+numbers[m]<target){
                    s=m+1;
                }
                else if(x+numbers[m]>target){
                    e=m-1;
                }
            }
        }
        return {-1,-1};
        
    }
};