class Solution {
public:
    void check(stack<int>& s){
        if(s.size()<2)return;
        int x=s.top();
        s.pop();
        int y=s.top();
        if(gcd(x,y)!=1){
            s.pop();
            s.push(lcm(x,y));
            if(s.size()>=2)check(s);
        }
        else{
            s.push(x);
            
        }    
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        s.push(nums[0]);
        for(int i=1; i<n;i++){
            
            int y=s.top();
            if(gcd(nums[i],y)!=1){
                s.pop();
                s.push(lcm(nums[i],y));
                check(s);
                
            }
            else{
                s.push(nums[i]);
                
            }
        }
        vector<int> ans;
        int m=s.size();
        for(int i=0 ; i<m ; i++){
            int x=s.top();
            s.pop();
            
            ans.push_back(x);
        }
        cout<<gcd(2009,899)<<" "<<gcd(899,20677);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};