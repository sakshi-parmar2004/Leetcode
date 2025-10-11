

class Solution {
public:
    long long solve(int i, vector<int>& power, long long dp[], unordered_map<int,int>& mp) {
        if (i >= power.size()) return 0;
        if (dp[i] != -1) return dp[i];

        // Option 1: skip
        long long skip = solve(i + 1, power, dp, mp);

        // Option 2: take and skip all numbers within diff <= 2
        int next_index = lower_bound(power.begin(), power.end(),
                                    power[i] + 3) -
                        power.begin();;
       

        long long take = 1LL * power[i] * mp[power[i]] + solve(next_index, power, dp, mp);

        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int> mp;
        for (int x : power) mp[x]++;

        sort(power.begin(), power.end());
        power.erase(unique(power.begin(), power.end()), power.end());

        long long dp[100005];
        memset(dp, -1, sizeof(dp)); // ✅ initialize all to -1

        return solve(0, power, dp, mp);
    }
};
