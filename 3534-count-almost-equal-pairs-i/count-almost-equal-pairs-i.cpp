class Solution {
public:
    
    bool dif(int a,int b){
        if(a==b)return true;        
        string x=to_string(a);
        string y=to_string(b);
        //cout<<x<<" "<<y<<endl;
        for(int i=0;i<x.size();i++){
            for(int j=i+1;j<x.size();j++){
                swap(x[i],x[j]);
                if(stoi(x)==stoi(y))return true;
                //cout<<x<<" "<<y<<endl;
                swap(x[i],x[j]);
            }
        }

        for(int i=0;i<y.size();i++){
            for(int j=i+1;j<y.size();j++){
                swap(y[i],y[j]);
                if(stoi(x)==stoi(y))return true;
                //cout<<x<<" "<<y<<endl;
                swap(y[i],y[j]);
            }
        }

        return false;
    }
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0 ; i<n ; i++ ){
            for(int j=i+1 ; j<n ; j++){
                if( dif(nums[i],nums[j])){
                    cnt++;
                    //cout<<nums[i]<<" "<<nums[j]<<endl;
                }
                
            }
        }
        return cnt;
    }
};