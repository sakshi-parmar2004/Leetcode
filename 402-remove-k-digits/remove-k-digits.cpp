class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If k still > 0, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build string from stack
        string str;
        while (!st.empty()) {
            str.push_back(st.top());
            st.pop();
        }
        reverse(str.begin(), str.end());

        // Remove leading zeros
        size_t pos = str.find_first_not_of('0');
        if (pos != string::npos) {
            str = str.substr(pos);
        } else {
            str = "0"; // all zeros
        }

        return str;
    }
};
