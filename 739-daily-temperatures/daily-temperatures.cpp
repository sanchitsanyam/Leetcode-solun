class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int m= temperatures.size();
        stack<int> st;
        vector<int> nge(m,0);
        for(int i=0;i<m;i++){
            while(st.size()!=0 && temperatures[st.top()]< temperatures[i]){
                nge[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return nge;
    }
};