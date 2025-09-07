class Solution {
public:
    long long  solve(int l, int r){
        long long L=1;
        long long S=1;
        long long steps=0;
        while(L<=r){
            long long R=L*4-1;
            long long start= max(L,(long long)l);
            long long end= min(R,(long long)r);
            if(start<=end)steps +=(end-start+1)*S;
            S+=1;
            L*=4;
        }
        return steps;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long  result=0;
        for(auto& q:queries){
            int l=q[0];
            int r=q[1];
            long long steps = solve(l,r);
            result += (steps+1)/2;
        }
        return result;
    }
};