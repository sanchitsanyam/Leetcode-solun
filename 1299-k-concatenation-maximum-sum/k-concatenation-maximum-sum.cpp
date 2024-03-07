class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        int gSum=0;//global  sum
        int Sum=0;
        int gmax=0;//global maxm(sumof maxm subarray)
        int cmaxSum=0;//current max sum
        int mod=1e9+7;
        gSum=accumulate(arr.begin(),arr.end(),gSum);
        int PreMaxSum=0;
        int SuffMaxSum=gSum;
        for(int i=0;i<n;i++){
            Sum+=arr[i];
            PreMaxSum=max(Sum,PreMaxSum);
            SuffMaxSum=max(gSum-Sum,SuffMaxSum);
            cmaxSum=max(cmaxSum+arr[i],arr[i]);
            gmax=max(gmax,cmaxSum);
        }
        if(k==1)return gmax;
        else{
            return max(max(0ll,(long long)(k-2)*Sum)+PreMaxSum+SuffMaxSum,(long long)gmax)%mod;
        }

        // https://youtu.be/bYUTYt8b3ds?si=_V_lSRkmujDFNq9l
    }
};