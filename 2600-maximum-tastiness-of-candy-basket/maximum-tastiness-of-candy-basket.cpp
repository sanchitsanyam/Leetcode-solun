class Solution {
public:
    bool check(int x, vector<int>& price, int k ){
        int j = 0;
        int len= 1 ;
        int n = price.size();
        for(int i = 0; i < n; i++){
            if( (price[i]-price[j]) >= x){
                len++;
                j=i;
            }
        }
        if(len>=k){
            return 1;
        }
        else{
            return 0;
        }

    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n = price.size();
        int r= price[n-1]-price[0];
        int l=0;
        int ans;
        while(l<=r){
            int m = (l+r)/2;
            int last_price=price[n-1];
            bool c=check(m, price, k);
            if(c){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
            
        }
        return ans;


        
    }
};