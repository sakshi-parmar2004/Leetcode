class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0,j=0,maxi=-1;
        unordered_map<int,int>mp;
        while(j<s.length())
        {
            mp[s[j]]++;
            while(i<j && mp[s[j]]==3)
            {
                mp[s[i]]--;
                i++;

            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
        
    }
};