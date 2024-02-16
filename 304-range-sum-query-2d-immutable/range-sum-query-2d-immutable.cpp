class NumMatrix {
public:
    int pre_arr[200][200];
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0){
                    pre_arr[i][j]=matrix[i][j];
                }
                else if(i==0){
                    pre_arr[i][j]=pre_arr[i][j-1]+matrix[i][j];
                }
                else if(j==0){
                    pre_arr[i][j]=pre_arr[i-1][j]+matrix[i][j];
                }
                else{
                    pre_arr[i][j]=pre_arr[i][j-1]+pre_arr[i-1][j]-pre_arr[i-1][j-1]+matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int r0, int c0, int r1, int c1) {
       int ans =pre_arr[r1][c1];
       if(r0>0)ans-=pre_arr[r0-1][c1];
       if(c0>0)ans-=pre_arr[r1][c0-1];
       if(c0>0 &&r0>0) ans+=pre_arr[r0-1][c0-1];
       return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */