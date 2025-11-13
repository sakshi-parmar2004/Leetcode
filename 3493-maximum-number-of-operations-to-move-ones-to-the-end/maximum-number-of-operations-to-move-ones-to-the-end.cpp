class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        vector<int> arr(n, 0);
        arr[0] = s[0] - '0';

        // build prefix sum of 1s
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + (s[i] - '0');
        
        }

        int i = 0, j = 0, ans = 0;

        while (j < n) {
            // find end of current group of identical bits
            while (j < n && arr[j] == arr[i]) {
                j++;
            }

            // group is s[i..j-1], length = j-i
            if (j - i > 1 && arr[i] != 0) {   // use arr[j-1] (end of group)
                ans += arr[i];
            }

            i = j; // move i to start of next group
        }

        return ans;
    }
};
