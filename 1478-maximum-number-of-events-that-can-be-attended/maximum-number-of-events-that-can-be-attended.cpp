class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b){
        if(a[1]<b[1])return true;
        else if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return false;
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end() ,comp);
        set<int> days;
        for(int i=1;i<=100000;i++)days.insert(i);
        int cnt=0;
        for(int i=0;i<events.size();i++){
            int s=events[i][0],e=events[i][1];
            auto it=days.lower_bound(s);
            if(it==days.end()||*it>e)continue;
            else{
                cnt++;
                days.erase(it);
            }    
        }
        return cnt;
    }
};