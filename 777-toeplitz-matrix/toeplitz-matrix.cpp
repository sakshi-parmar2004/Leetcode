class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        // Start from first row
        for (int j = 0; j < n; j++) {
            int val = matrix[0][j];
            int a = 1, b = j + 1;
            while (a < m && b < n) {
                if (matrix[a][b] != val) return false;
                a++;
                b++;
            }
        }

        // Start from first column (skip (0,0) since already checked)
        for (int i = 1; i < m; i++) {
            int val = matrix[i][0];
            int a = i + 1, b = 1;
            while (a < m && b < n) {
                if (matrix[a][b] != val) return false;
                a++;
                b++;
            }
        }

        return true;
    }
};
