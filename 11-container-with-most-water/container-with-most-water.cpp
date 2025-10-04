class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int p1=0;
        int p2=n-1;
        int area=0;
        while(p1<p2){
            int l=min(h[p1],h[p2]);
            int x=l*(p2-p1);
            area=max(area,x);
            if(h[p1]<h[p2]){
                p1++;
            }
            else{
                p2--;
            }
        }
        return area;
    }
};