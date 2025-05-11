class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<bool> seen(100001,false);
        vector<int>   st(200001);
        int top=0;
        int ans=0;
        for(int curr: nums){
            if(curr==0){
                while(top){
                    seen[st[--top]]=false;
                }
               continue;
            }
            while(top && st[top-1]>curr){
                seen[st[--top]]=false;
            }
            if(!seen[curr]){
                ans++;
                seen[curr]=true;
            }
            st[top++]=curr;

        }
        return ans;
    }
};