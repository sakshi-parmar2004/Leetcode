class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, n = version1.size(), m = version2.size();

        while (i < n || j < m) {
            long val1 = 0, val2 = 0;

            // parse next number in version1
            while (i < n && version1[i] != '.') {
                val1 = val1 * 10 + (version1[i] - '0');
                i++;
            }

            // parse next number in version2
            while (j < m && version2[j] != '.') {
                val2 = val2 * 10 + (version2[j] - '0');
                j++;
            }

            if (val1 > val2) return 1;
            if (val1 < val2) return -1;

            // skip dots
            i++;
            j++;
        }
        return 0;
    }
};
