class Solution {
public:
    long long countDistinct(long long n) {

        string s = to_string(n);
        int m = s.length();

        vector<long long> pow_9(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow_9[i] = pow_9[i - 1] * 9LL;
        }

        long long ans = 0;

        for (int len = 1; len < m; len++) {
            ans += pow_9[len];
        }

        for (int i = 0; i < m; i++) {
            int d = s[i] - '0';
            if (d == 0) return ans;
            ans += (long long)(d - 1) * pow_9[m - i - 1];
        }

        return ans + 1;
    }
};
