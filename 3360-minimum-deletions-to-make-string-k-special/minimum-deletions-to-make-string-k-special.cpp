class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char,int> mp;
        int n=word.size();
        for(int i=0;i<n;i++){
            mp[word[i]]++;
        }
        vector<int> a;
        for(auto c:mp){
            if(c.second>0){
                a.push_back(c.second);
            }
        }
        sort(a.begin(),a.end());
        int sum=0;
        int ans=INT_MAX;
        for(int i=0;i<a.size();i++){
            int curr=0;
            for(int j=i+1;j<a.size();j++){
                if((a[i]+k)<a[j]){
                    curr+=(a[j]-a[i]-k);
                }
            }
            ans=min(ans,curr+sum);
            sum+=a[i];
        }
        return ans;
                                       
    }
};