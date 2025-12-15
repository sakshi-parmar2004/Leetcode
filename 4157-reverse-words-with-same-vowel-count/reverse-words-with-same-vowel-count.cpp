class Solution {
public:
    string reverseWords(string s) {
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        
        int n = s.length();
        int i = 0, count = 0;
        string ans = "", word = "";

        // First word
        while (i < n && s[i] != ' ') {
            ans += s[i];
            if (st.count(s[i])) count++;
            i++;
        }

        ans += ' ';
        i++;  // skip space

        int vowels = 0;

        while (i <= n) {
            if (i == n || s[i] == ' ') {
                if (vowels == count)
                    reverse(word.begin(), word.end());

                ans += word;
                if (i != n) ans += ' ';
                
                word = "";
                vowels = 0;
            } else {
                word += s[i];
                if (st.count(s[i])) vowels++;
            }
            i++;
        }

        int len= ans.length();
        if(len>0 && ans[len-1]==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};
