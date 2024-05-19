class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
        int n1=q.size();
        int n=a.size();
         vector<bool> ans;
        if(n==1){
            for(int i=0;i<n1;i++){
                ans.push_back(true); 
            }
            return ans;
        }
        vector<int> sp(n-1);
        for(int i=0; i<n-1;i++){
            if((a[i]%2==0) &&(a[i+1]%2==0)){
                sp[i]=1;
            }
            else if((a[i]%2!=0 || a[i]==1) &&(a[i+1]%2!=0 || a[i+1]==1)){
                sp[i]=1;
            }
            else{
                sp[i]=0;
            }
        }
        vector<int> Ssp(n);
        Ssp[0]=sp[0];
        for(int i=1;i<n-1;i++){
            Ssp[i]=Ssp[i-1]+sp[i];
        }
        Ssp[n-1]=(n-2)?Ssp[n-2]:0;
        
        for( int i=0; i<n1 ;i++){
            int left=q[i][0];
            int right=q[i][1];
            int ans1=((right)?Ssp[right-1]:0)-((left)?Ssp[left-1]:0);
            if(ans1==0)ans.push_back(true);
            else ans.push_back(false);

        }
        return ans;
        
    }
};