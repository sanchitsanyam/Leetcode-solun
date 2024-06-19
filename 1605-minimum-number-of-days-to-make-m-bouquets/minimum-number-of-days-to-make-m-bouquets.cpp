class Solution {
public:
// https://youtu.be/TXAuxeYBTdg?si=UZhVG0FtEg2BYB3z
    bool possible(vector<int>& bloomDay ,int m , int k , int d){
        int n=bloomDay.size();
        int nobq=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if( d>=bloomDay[i]){
               cnt++;
            }
            else{
                nobq +=(cnt/k);
                cnt=0;
            }
        }
        nobq +=(cnt/k);
        return nobq>=m;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val= m*1ll*k*1ll;
        int n=bloomDay.size();
        if(val> n )return -1;
        int minD = INT_MAX;
        int maxD = INT_MIN;
        for(int i=0;i<n;i++){
            if(minD>bloomDay[i]){
                minD=bloomDay[i];
            }
            if(bloomDay[i]> maxD){
                maxD=bloomDay[i];
            }
        }
        int l=minD, r=maxD;
        while(l<=r){
            int mid=(l+r)/2;
            if(possible( bloomDay , m ,  k ,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;

        
    }
};