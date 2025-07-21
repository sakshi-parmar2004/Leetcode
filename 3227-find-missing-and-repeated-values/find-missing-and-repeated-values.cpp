class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long sum = 0, sq_sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                sq_sum += 1LL * grid[i][j] * grid[i][j];
            }
        }

        long long num = n * n;
        long long cal_sum = num * (num + 1) / 2;
        long long cal_sq_sum = num * (num + 1) * (2 * num + 1) / 6;

        long long value1 = cal_sum - sum;             // M - R
        long long value2 = cal_sq_sum - sq_sum;       // M^2 - R^2

        long long M_plus_R = value2 / value1;         // M + R

        long long missing = (value1 + M_plus_R) / 2;
        long long repeating = missing - value1;

        return {(int)repeating, (int)missing};
    }
};
