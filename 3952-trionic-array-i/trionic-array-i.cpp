class Solution {
public:
    bool isTrionic(vector<int>& a) {
        int l=0;
        int n=a.size();
        int r=n-1;
        for(int i=0;i<n-1;i++){
            if(a[i]<a[i+1])l++;
            else break;
        }
        for(int i=n-1;i>0;i--){
            if(a[i]>a[i-1])r--;
            else break;
        }
        if(l==n-1 || r==0)return false;
        if( ( l==0 || r==n-1))return false;
        if(a[l+1]==a[l] || a[r-1]==a[r])return false;
        for(int j=l+1;j<r-1;j++){
            if(a[j]<=a[j+1])return false;
        }
        return true;
    }
};