class Solution {
public:
    void mergeR(vector< int>& nums, int l, int m, int r){
         int revPair=0;
         int lftsz=m-l+1;
         int rtsz=r-m;
        vector< int>lft(lftsz,0);
        vector< int>rt(rtsz,0);
        for(int i=0;i<lftsz;i++){
            lft[i]=nums[i+l];
        }
        for(int i=0;i<rtsz;i++){
            rt[i]=nums[i+m+1];
            
        }
        int i=0,j=0,k=l;
        while(i<lftsz && j<rtsz){
            if(lft[i]<=rt[j]){
                nums[k]=lft[i];
                k++;
                i++;
            }
            else{
                nums[k]=rt[j];
                k++;
                j++;
            } 
        }
        while(i<lftsz){
            nums[k]=lft[i];
            k++;
            i++;
        }
        while(j<rtsz){
            nums[k]=rt[j]; 
            
            k++;
            j++;
        }
        
    }
    long long revSortPair(vector<int>& nums, int l, int m, int r) {
        long long revPair = 0;
        int right = m + 1;
        for (int i = l; i <= m; i++) {
            while (right <= r && static_cast<long long>(nums[i]) > 2LL * nums[right]) right++;
            revPair += (right - (m + 1));
        }
        return revPair;
    }

    long long mergeRsort(vector<int>& nums, int l, int r) {
        long long revPair = 0;
        if (l < r) {
            int mid = l + (r - l) / 2;
            revPair += mergeRsort(nums, l, mid);
            revPair += mergeRsort(nums, mid + 1, r);
            revPair += revSortPair(nums, l, mid, r);
            mergeR(nums, l, mid, r);
        }
        return revPair;
    }

    long long reversePairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        return mergeRsort(nums, l, r);
    }
 
};