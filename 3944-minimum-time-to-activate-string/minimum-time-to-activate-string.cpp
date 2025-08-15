class Solution {
public:
    long long solve(const string &str) {
        int n = str.length();
        long long total = 1LL * n * (n + 1) / 2;
        long long no_start = 0, len = 0;

        for (char c : str) {
            if (c == '*') {
                no_start += 1LL * len * (len + 1) / 2;
                len = 0;
            } else {
                len++;
            }
        }
        no_start += 1LL * len * (len + 1) / 2;
        return total - no_start;
    }

    int minTime(string s, vector<int>& order, int k) {
        int left = 0, right = order.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            string str = s;
            for (int i = 0; i <= mid; i++) {
                str[order[i]] = '*';
            }

            if (solve(str) >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
