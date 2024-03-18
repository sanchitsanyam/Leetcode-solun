class Solution {
public:
    int binarySearch(vector<int>& arr,int l,int r,int k){
        int m;
        while(l<=r){
            m=l+(r-l)/2;
            if(arr[m]==k){
                return m;
            }
            else if(arr[m]<k){
                l=m+1;
                
            }
            else{
                r=m-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int p;//p->pivot index
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]>nums[r]){
                l=m+1;
            }
            else{
                r=m;
            }
        }
         p=l;
        int a=binarySearch(nums,0,p-1,target);
        int b=binarySearch(nums,p,n-1,target);
        if(a==-1){
            return b;
        }
        else if(b==-1){
            return a;
        }
        return -1;
    }
};