class Solution {
public:
    int trap(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int maxLeft= heights[i];
        int maxRight= heights[j];
        int result=0;
        while(i<j){
            if(maxLeft <= maxRight){
                i++;
                maxLeft = max(maxLeft,heights[i]);
                result += maxLeft-heights[i];
            }
            else{
                j--;
                maxRight = max(maxRight,heights[j]);
                result += maxRight-heights[j];
            }
        }
        return result;

    }
};