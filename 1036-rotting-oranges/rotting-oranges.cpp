class Solution {
public:
    vector<vector<int>> arr{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(),count=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for (int it = 0; it < 4; it++) {
                int newi = i + arr[it][0];
                int newj = j + arr[it][1];
                if (newi >= 0 && newj >= 0 && newi < m && newj < n &&
                    !visited[newi][newj] && grid[newi][newj] == 1) {
                    q.push({{newi, newj}, t + 1});
                    visited[newi][newj] = true;
                }
            }
            count = t;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    return -1;
                }
            }
        }
        return count;
    }
};