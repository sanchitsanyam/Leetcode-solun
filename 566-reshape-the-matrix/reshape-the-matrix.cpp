class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(m*n !=r*c)return mat;
        vector<int> ans(r*c);
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0 ; j<m ; j++){
                ans[t]=mat[i][j];
                t++;
            }
        }
        vector<vector<int>> fans(r,vector<int>(c,0));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                fans[i][j]=ans[k];
                k++;
            }
        }
        return fans;
        
    }
};