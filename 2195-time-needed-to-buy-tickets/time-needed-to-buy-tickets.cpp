class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        stack<int> s;
        int n = tickets.size();
        int cnt=0;
        while(tickets[k]!=0){
            for(int i=0;i<n;i++){
                if(tickets[i]>0){
                    cnt++;
                    tickets[i]--;
                    if(tickets[k]==0){
                        break;
                    }
                }
                
            }
        }
        return cnt;
    }
};