#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int ops) {
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;

        vector<int> diff_arr(maxi + k + 2, 0);

        for (int x : nums) {
            int l = max(0, x - k);
            int r = min((int)diff_arr.size() - 2, x + k);
            diff_arr[l]++;
            diff_arr[r + 1]--;  // ✅ fixed sign
        }

        int result = 0;
        for (int i = 0; i < diff_arr.size(); i++) {
            if (i > 0) diff_arr[i] += diff_arr[i - 1];

            int already = mp[i];
            int needed = diff_arr[i] - already;
            int value = min(needed, ops);
            result = max(result, already + value);
        }

        return result;
    }
};
