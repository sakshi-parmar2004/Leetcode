class Solution {
public:
    bool isZero(int k, vector<vector<int>>& queries, vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] -= val;
            if (r + 1 < n) diff[r + 1] += val;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (nums[i] + sum > 0) return false; // still positive
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0, r = queries.size(), ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isZero(mid, queries, nums)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
