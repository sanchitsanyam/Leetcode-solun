class Solution {
public:
    vector<string> ans; // To store valid expressions
    int target;         // Target value

    // Helper function for recursive exploration
    void help(int i, long prev, long curr, string& num, string expr) {
        // Base case: if we've processed all digits
        if (i == num.size()) {
            if (curr == target) {
                ans.push_back(expr); // If the current value matches the target, add to result
            }
            return;
        }

        for (int j = i; j < num.size(); j++) {
            // Extract the current number as a substring
            string part = num.substr(i, j - i + 1);
            long val = stol(part);

            // Skip numbers with leading zeros (except single '0')
            if (part.size() > 1 && part[0] == '0') break;

            // If this is the first number, start the expression
            if (i == 0) {
                help(j + 1, val, val, num, expr + part);
            } else {
                // Addition
                help(j + 1, val, curr + val, num, expr + "+" + part);
                // Subtraction
                help(j + 1, -val, curr - val, num, expr + "-" + part);
                // Multiplication
                help(j + 1, prev * val, curr - prev + (prev * val), num, expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->target = target;
        if (num.empty()) return ans;

        // Start the recursion
        help(0, 0, 0, num, "");
        return ans;
    }
};
