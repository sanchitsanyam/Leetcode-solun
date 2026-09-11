class Solution {
public:
    int totalNumbers(vector<int>& ans) {
        set<int> s;
        int n=ans.size();
        for(int i=0;i<n;i++){
            if(ans[i]==0)continue;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                for(int k=0;k<n;k++){
                    if(j==k|| i==k)continue;
                    if(ans[k]%2)continue;
                    int a=ans[i]*100+ans[j]*10+ans[k];
                    s.insert(a);
                }
            }
        }
        return s.size();
        
    }
};