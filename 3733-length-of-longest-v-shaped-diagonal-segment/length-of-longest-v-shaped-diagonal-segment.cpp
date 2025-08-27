class Solution {
public:
    int m, n;
    vector<vector<int>> grid;

    // dir: 1=top-right, 2=bottom-right, 3=bottom-left, 4=top-left
    int solve(int r, int c, bool turned, int dir, int expected) {
        if (r < 0 || c < 0 || r >= m || c >= n) return 0;
        if (grid[r][c] != expected) return 0;

        int ans = 0;

        if (dir == 1) { // top-right
            ans = 1 + solve(r - 1, c + 1, turned, 1, 2 - expected);
            if (!turned) ans = max(ans, 1 + solve(r + 1, c + 1, true, 2, 2 - expected));
        }
        else if (dir == 2) { // bottom-right
            ans = 1 + solve(r + 1, c + 1, turned, 2, 2 - expected);
            if (!turned) ans = max(ans, 1 + solve(r + 1, c - 1, true, 3, 2 - expected));
        }
        else if (dir == 3) { // bottom-left
            ans = 1 + solve(r + 1, c - 1, turned, 3, 2 - expected);
            if (!turned) ans = max(ans, 1 + solve(r - 1, c - 1, true, 4, 2 - expected));
        }
        else if (dir == 4) { // top-left
            ans = 1 + solve(r - 1, c - 1, turned, 4, 2 - expected);
            if (!turned) ans = max(ans, 1 + solve(r - 1, c + 1, true, 1, 2 - expected));
        }

        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& g) {
        grid = g;
        m = grid.size(), n = grid[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // must start with 1
                    ans = max(ans, 1 + solve(i - 1, j + 1, false, 1, 2));
                    ans = max(ans, 1 + solve(i + 1, j + 1, false, 2, 2));
                    ans = max(ans, 1 + solve(i + 1, j - 1, false, 3, 2));
                    ans = max(ans, 1 + solve(i - 1, j - 1, false, 4, 2));
                }
            }
        }
        return ans;
    }
};
