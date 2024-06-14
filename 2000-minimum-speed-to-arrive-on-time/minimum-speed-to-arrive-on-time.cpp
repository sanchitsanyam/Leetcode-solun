class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l=1;
        int r=1e7+9;
        while( l<r){
            int mid = (l+r)/2;
            double t=0;
            for(int i=0; i<n; i++){
                if(t > (int) t){
                    t=(double)((int)t+1);
                }
                t +=((double)(dist[i]))/((double)(mid));   
            }
            if(t> hour){
                l=mid+1;
            }    
            else{
                r = mid;
            }
           
        }
        return (l>=1e7+9 ?-1:l);

    }
};