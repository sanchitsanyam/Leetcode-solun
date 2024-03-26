class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=1;
        int e=n-2;
        if(arr[0]<arr[1]&&arr[1]>arr[2])return 1;
        while(s<=e){
            int m=e+(s-e)/2;
            if(arr[m-1]<=arr[m]&&arr[m]>=arr[m+1]) return m;
            else if(arr[m-1]<arr[m]&&arr[m]<arr[m+1]){
                s=m+1;
            }
            else if(arr[m-1]>arr[m]&&arr[m]>arr[m+1]){
                e=m-1;
            }
        }
        return -1;

    }
};