class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& a, int k) {
        if(k==1)return true;
        int n=a.size();
        int prev=0;
        int curr=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){
               curr++;
            }
            else{
                if(prev>=k && curr>=k)return true;
                else if (curr>=2*k)return true;
                else{
                    prev=curr;
                    curr=1;
                }
            }
        }
        if(prev>=k && curr>=k)return true;
        else if (curr>=2*k)return true;
        return false;
    }
};