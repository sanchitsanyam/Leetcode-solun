class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n=points.size();
        int finalAns=INT_MIN;
        deque<int> q;
        for(int j=0; j<n; j++){
            //  int y_minus_x=points[j][1]-points[j][0];
            // while(q.size() && (points[q.back()][1]-points[q.back()][0]) <= y_minus_x){
            //     q.pop_back();
            // }
            // q.push_back(j);
            while(q.size() && points[q.front()][0]<(points[j][0]-k)){
                q.pop_front();
            }
            if(q.size()){
               int i=q.front();
                finalAns=max(finalAns,points[j][0]+points[j][1]+points[i][1]-points[i][0]); 
            }
            int y_minus_x=points[j][1]-points[j][0];
            while(q.size() && (points[q.back()][1]-points[q.back()][0]) <= y_minus_x){
                q.pop_back();
            }
            q.push_back(j);
            
            

        }
        return finalAns;
    }
};