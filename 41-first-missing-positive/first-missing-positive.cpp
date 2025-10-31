class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Replace all non-positive and large values with n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;
        }

        // Step 2: Use index marking
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val <= n && nums[val-1]>0)
                nums[val - 1] *= -1;
        }

        // Step 3: First positive index is the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        // Step 4: All 1..n are present
        return n + 1;
    }
};
