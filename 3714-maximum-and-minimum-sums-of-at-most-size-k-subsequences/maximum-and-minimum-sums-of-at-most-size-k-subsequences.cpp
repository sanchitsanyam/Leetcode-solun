const int Q=1e9+7;
const int N=1e5+7;
const int M=109;
class Solution {
public:
    int c[N][M];
    int add(int x, int y ){
        x+=y;
        if(x>=Q) x-=Q;
        return x;
    }
    int pdt(int x ,int y){
        return (1ll*x*y )%Q;
    }
    int minMaxSums(vector<int>& nums, int k) {
        c[0][0]=1;
        c[1][0]=1;
        c[1][1]=1;
        int n=nums.size();
        for(int i =2;i<=n ;i++){
            c[i][0]=1; if(i<M)c[i][i]=1;
            for(int j=1;j<=k && j<i ;j++){
                c[i][j]=add(c[i-1][j],c[i-1][j-1]);
            }
        }
        int m=n-1;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int s=nums[i];
            int p=0;
            for(int j=0;j<k && j<=m ;++j){
                p=add(p,c[m][j]);
            }
            m--;
            ans=add(ans,pdt(s,p));
        }
        m=n-1;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int s=nums[i];
            int p=0;
            for(int j=0;j<k && j<=m ;++j){
                p=add(p,c[m][j]);
            }
            m--;
            ans=add(ans,pdt(s,p));
        }
        return ans;

    }
};