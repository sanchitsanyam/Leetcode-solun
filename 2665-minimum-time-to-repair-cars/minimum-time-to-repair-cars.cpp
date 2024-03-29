class Solution {
public:
    long long ck(vector<int>& ranks,long long  t){
        long long  ans=0;
        for(int i=0;i<ranks.size();i++){
           ans+=sqrt(t/ranks[i]); 
        }
        return ans;
    }
    long long repairCars(vector<int>& ranks, int cars){
        long long s=1;
        long long e=1e14;
        while(s<=e){
            long long m=s+(e-s)/2;
            if(ck(ranks, m)>=cars){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return e+1;
    }
};