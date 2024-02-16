class Solution {
public:
    int alternatingSubarray(vector<int>& n) {
        int curr=0;
        int ans=0;
        int t=n.size();
        for(int i=1;i<t;i++){
            if(n[i]-n[i-1]==1){
                if(curr%2==0)curr++;
                else{
                   curr=1;
                }
            }
            else if(n[i]-n[i-1]==-1){
                if(curr%2!=0)curr++;
                else{
                    curr=0;
                }
            }
            else{
                curr=0;
            }
            ans=max(ans,curr+1);
        }
        if(ans==1)return -1;
        return ans;
    }
};