class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
    
        long long n=prices.size();
        long long min1=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            if(prices[i]<=min1){
                min1=prices[i];
                j=i;
         
            }
        }
        cout<<min1<<endl;
        long long min2=INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<min2 && i!=j){
                min2=prices[i];
              
            }
        }
        cout<<min2<<endl;
        
        if(money>=(min1+min2)){
            return money-(min1+min2);
        }
        else{
            return money;
        }
    }
};