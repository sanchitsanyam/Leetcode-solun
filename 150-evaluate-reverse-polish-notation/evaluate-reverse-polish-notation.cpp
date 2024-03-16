class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                int res;
                if (tokens[i] == "+") {
                    res = op1 + op2;
                } else if (tokens[i] == "-") {
                    res = op1 - op2;
                } else if (tokens[i] == "*") {
                    res = op1 * op2;
                } else if (tokens[i] == "/") {
                    res = op1 / op2;
                }
                st.push(res);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};