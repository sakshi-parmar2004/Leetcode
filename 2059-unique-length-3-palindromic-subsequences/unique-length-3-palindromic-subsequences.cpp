class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_set<char>st1;
        for(int i=0;i<s.length();i++)
        {
            if(st1.find(s[i])!=st1.end())
            {
                continue;
            }
            st1.insert(s[i]);
            int r = s.rfind(s[i]);
            unordered_set<char>st;
            for(int j=i+1;j<r;j++)
            {
                st.insert(s[j]);
            }

            ans+=st.size();
        }
        return ans;
        
    
    }

};