class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
       vector<int> arr(n); 
        for(int i=k;i<k+n;i++){
            arr[(i+k)%n]=nums[i%n];
        }
        for(int i=0;i<n;i++){
            nums[i]=arr[i];
        }
    }    
};