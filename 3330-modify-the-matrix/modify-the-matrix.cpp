class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int j=0,max=INT_MIN;
        while(j<m){
            max=INT_MIN;
            for(int i=0;i<n;i++){
                if(matrix[i][j]>max){
                    max=matrix[i][j];
                }
            }
            for(int i=0;i<n;i++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=max;
                }
            }
            j++;
            
        }
        return matrix;
    }
};