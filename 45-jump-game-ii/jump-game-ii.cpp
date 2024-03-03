class Solution {
public:
    int jump(vector<int>& a) {
        //https://youtu.be/9kyHYVxL4fw?si=klQTkt7KjZXQeZZw
        int destination=a.size()-1;
        int totaljumps=0;
        int coverage=0;
        int lastJumpIdx=0;
        if(a.size()==1)return 0;
        for(int i=0;i<a.size();i++){
            coverage=max(coverage,a[i]+i);
            if(i==lastJumpIdx){
                lastJumpIdx=coverage;
                totaljumps++;
                if(coverage>=destination){
                    return totaljumps;
                }
            }
        }
        return -1;
        
    }
};