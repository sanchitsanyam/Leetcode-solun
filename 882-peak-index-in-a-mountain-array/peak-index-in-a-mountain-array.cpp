class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int m=r+(l-r)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){
               return m;
            }
            if(arr[m]>arr[m-1]){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return -1;
    }
};