class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (m > n) return {};
        
        vector<int> ans;
        vector<int> freqP(26, 0), freqS(26, 0);

        // build frequency of p
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int i = 0;
        for (int j = 0; j < n; j++) {
            freqS[s[j] - 'a']++;

            if (j - i + 1 > m) {
                freqS[s[i] - 'a']--;
                i++;
            }

            if (freqS == freqP) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

