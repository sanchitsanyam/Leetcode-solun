class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        auto sum =0;
        for(auto n : nums){
            auto last_d=0;
            for(int j=2;j*j<=n;j++){
                if(n%j==0){
                    if(last_d==0){
                        last_d=j;
    
                    }
                    else{
                        last_d=0;
                        break;
                    }
                }
            }
            if(last_d>0 && last_d !=(n/last_d)){
                sum+=1+n+last_d+(n/last_d);
            }

        }
        return sum;
    }
};