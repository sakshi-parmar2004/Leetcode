class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        string ans = s;
        vector<int> freq(128, 0); // ASCII size is 128

        // count frequency of vowels
        for (char c : s) {
            if (st.find(c) != st.end()) {
                freq[(int)c]++;
            }
        }

        int k = 0;
        for (int i = 0; i < s.length(); i++) {
            if (st.find(s[i]) != st.end()) {
                while (k < 128 && freq[k] == 0) k++;
                ans[i] = (char)k;
                freq[k]--;
            }
        }

        return ans;
    }
};
