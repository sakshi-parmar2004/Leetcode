class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (k == 0) return nums; // each element is its own average
        if (2*k+1 > n) return ans; // window too large for any average

        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for (int i = 0; i + 2*k < n; i++) {
            long long total = prefix[i+2*k] - (i > 0 ? prefix[i-1] : 0);
            ans[i+k] = total / (2*k+1);
        }

        return ans;
    }
};
