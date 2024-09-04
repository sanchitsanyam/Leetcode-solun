class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp(n+1);
        dp[1]=1;
        int p2=1;
        int p3=1;
        int p5=1;
        for(int i = 2 ; i <= n ; i++){
            int f1= 2*dp[p2];
            int f2= 3*dp[p3];
            int f3= 5*dp[p5];
            int minm=min(f1 ,min(f2,f3));
            dp[i]=minm;
            if(minm==f1){
                p2++;
            }
            if(minm==f2){
                p3++;
            }
            if(minm==f3){
                p5++;
            }
        }
        return dp[n];

    }
};