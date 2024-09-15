class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> interval;
        int n = startTime.size();
        for(int i = 0 ;i < n ; i++){
            interval.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(interval.begin(), interval.end(),comp);
        vector<int> p(n,-1);
        for(long long i=1;i<n;i++){
            int t=interval[i][0];
            for(long long j=i-1; j >= 0 ; j--){
                if(t >= interval[j][1]){
                    p[i]=j;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
        vector<int> opt(n);
        opt[0]=interval[0][2];
        for(int j=1; j<n ;j++){
            int k1= opt[j-1];
            int k2;
            if(p[j]!=-1){
                k2=interval[j][2]+opt[p[j]];
            }
            else{
                k2=interval[j][2];
            }
            opt[j]=max(k1,k2);
        } 
        for(int i=0;i<n;i++){
            cout<<opt[i]<<" ";
        }
        cout<<endl;
        return  opt[n-1];      

    }
};