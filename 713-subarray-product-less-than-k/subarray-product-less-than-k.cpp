class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int n=a.size();
        int c=0,s;
        for(int i=0;i<n;i++){
            s=a[i];
            if(a[i]<k){
                c++;
            }
            for(int j=i+1;j<n;j++){
                s=s*a[j];
                if(s<k){
                    c++;
                }
                else{
                    break;
                }
            }
        }
        return c;

    }
};