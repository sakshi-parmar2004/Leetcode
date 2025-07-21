class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});  // First row

        for (int i = 1; i < n; i++) {
            // Create a row of size i+1, filled with 0
            vector<int> row(i + 1, 0);

            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    row[j] = 1;  // First and last element is always 1
                } else {
                    row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
            }

            ans.push_back(row);  // Add the row to the result
        }

        return ans;
    }
};
