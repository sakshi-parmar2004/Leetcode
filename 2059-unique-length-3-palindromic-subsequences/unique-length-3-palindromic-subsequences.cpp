class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]].push_back(i);
        }

        for(auto i:mp)
        {
            vector<int>arr= i.second;
            if(arr.size()==1)continue;
            unordered_set<char>st;
            if(arr.size()>2)st.insert(i.first);
            for(int i=0;i<arr.size()-1;i++)
            {
                int l= arr[i],r=arr[i+1];
                for(int j=l+1;j<r;j++)
                {
                    st.insert(s[j]);
                }
            }

            ans+=st.size();
        }

        return ans;
    }

};