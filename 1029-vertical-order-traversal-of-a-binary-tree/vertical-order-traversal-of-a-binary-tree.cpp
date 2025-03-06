class Solution {
public:
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    int minCol = 0, maxCol = 0;

    int diameter(TreeNode* root, int& height) {
        if (root == nullptr) {
            height = 0;
            return 0;
        }

        int lh = 0, rh = 0;
        int ld = diameter(root->left, lh);
        int rd = diameter(root->right, rh);

        height = max(lh, rh) + 1;
        return max({ld, rd, lh + rh + 1});
    }

    void dfs(TreeNode* root, int row, int col) {
        if (root == nullptr) return;

        minCol = min(minCol, col);
        maxCol = max(maxCol, col);

        nodes[col][row].insert(root->val);

        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int height = 0;
        int diam = diameter(root, height);
        cout << "Diameter: " << diam << endl;

        dfs(root, 0, 0);

        for (int col = minCol; col <= maxCol; col++) {
            vector<int> colNodes;
            for (auto& [row, values] : nodes[col]) {
                colNodes.insert(colNodes.end(), values.begin(), values.end());
            }
            ans.push_back(colNodes);
        }

        return ans;
    }
};
