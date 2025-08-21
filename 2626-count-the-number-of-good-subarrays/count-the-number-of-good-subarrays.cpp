class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        long long ans = 0;
        long long count = 0;
        unordered_map<int,int> mp;

        while (j < n) {
            count += mp[nums[j]];   
            mp[nums[j]]++;

            while (i < j && count >= k) {
                ans += (n - j);   
                mp[nums[i]]--;
                count -= mp[nums[i]];  
                if (mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            j++;
        }
        return ans;
    }
};
