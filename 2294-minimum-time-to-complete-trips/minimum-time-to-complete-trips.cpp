class Solution {
public:
    long long CalTrip(vector<int>& time, long long t){
        long long ans=0;
        for(int i=0;i<time.size();i++){
            ans+=t/time[i];
        }
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=1;
        long long e=time[0];
        // long long r=time[0]*totalTrips;
        // if(time.size()==1)return r;
        for(int i=0;i<time.size();i++){
            e=min((long long)(time[i]),e);
        }
        e=totalTrips*e;
        long long ans=-1;
        while(s<=e){
            long long m=s+(e-s)/2;
            long long t=CalTrip(time,m);
            if(t>=totalTrips){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};