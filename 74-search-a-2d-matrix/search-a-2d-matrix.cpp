class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int l=0;
        int h=r*c-1;
        while(l<=h){
            int m=(l+h)/2;
            int mi=(m/c);
            int mj=(m)%c;
            if(matrix[mi][mj]==target)return true;
            if(matrix[mi][mj]>target){
                h=m-1;
            }
            else if(matrix[mi][mj]<target){
                l=m+1;
            }

        }
        return false;
    }
};