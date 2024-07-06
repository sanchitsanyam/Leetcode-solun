class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        
        vector<int> arr(n,0);
        
        for(int i=0; i<n; i++){
            arr[i]=tickets[i];
        }
        int ans=0;
        while(arr[k]>0){
            for(int i=0;i<n;i++){
                if(arr[i]>0){
                   if(arr[k]==0){
                       break;
                   }
                   ans+=1;
                }
                
                arr[i] =arr[i]-1;
            }    
        }
        return ans;
    }
};