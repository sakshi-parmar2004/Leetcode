class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int n = s2.size(), m = s1.size();
        if (m > n) return {};
        
        vector<int> ans;
        vector<int> freqP(26, 0), freqS(26, 0);

        // build frequency of p
        for (char c : s1) {
            freqP[c - 'a']++;
        }

        int i = 0;
        for (int j = 0; j < n; j++) {
            freqS[s2[j] - 'a']++;

            if (j - i + 1 > m) {
                freqS[s2[i] - 'a']--;
                i++;
            }

            if (freqS == freqP) {
                return true;
            }
        }
        return false;
        
    }
};