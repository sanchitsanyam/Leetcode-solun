class Solution {
public:
    bool check(vector<int>& start, int d, long long mid){
        long long prev=start[0];
        for(int i=1 ; i < start.size() ; i++){
            long long int next = max( prev+mid , static_cast<long long>(start[i]));
            if(next>(start[i]+d)){
                return false;
            }
            prev=next;
        }  
        return true;  

    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        long long low=0 ,hii=start.back()-start.front()+d;
        long long ans=0;
        while(low <= hii){
            long long mid = (low +hii)/2;
            if(check(start , d ,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                hii=mid-1;
            }
        }
        return ans;

    }
};