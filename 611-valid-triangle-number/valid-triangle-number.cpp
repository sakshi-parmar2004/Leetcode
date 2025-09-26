class Solution {
public:
    int bin_search(int l, int r, int target, vector<int>& nums) {
        int result = r + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                result = mid;
                r = mid - 1;
            } else {

                l = mid + 1;
            }
        }
        return result;
    }
    int triangleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};