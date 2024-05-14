class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n1=h.size();
        vector<int> n(n1,-1);
        vector<int> p(n1,-1);
        stack<int> s1;
        stack<int> s;
        
        for(int i=n1-1;i>=0;i--){
            while(!s1.empty() && h[s1.top()]>=h[i]){
                s1.pop();
            }
            
            n[i]=s1.empty()?n1:s1.top();
            s1.push(i);
            cout<<n[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n1;i++){
            while(!s.empty() && h[s.top()]>=h[i]){
                s.pop();
            }
            
            p[i]=s.empty()?-1:s.top();
            s.push(i);
            cout<<p[i]<<" ";
        }
        cout<<endl;
        int marea=INT_MIN;
        int area;
        for(int i=0;i<n1;i++){
            
            area=h[i]*(n[i]-p[i]-1);
            
            if(area>marea){
                marea=area;
            }
        }
        return marea;

    }
};