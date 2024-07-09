class Solution {
public:
    long long time(vector<int>& piles , int s){
        long long time=0;
        
        for(int i=0;i<piles.size();i++){
            if(piles[i]%s!=0){
                time+=(piles[i]/s)+1;
            }
            else{
               time+=piles[i]/s;
            }
            
        }
        return time;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxm=INT_MIN;
        
    
        for(int i=0;i<piles.size();i++){
            maxm=max(piles[i],maxm);
            
        }
        long long l=1;
        long long  r=maxm;
        int ans=-1;
        while(l<=r){
            long long m=(l+r)/2;
            if(time(piles,m)<=h){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }

};