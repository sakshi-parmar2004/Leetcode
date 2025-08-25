class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len= p.length() , n= s.length(),j=0,i=0;
        unordered_map<char,int>mp;
        for(char i:p)
        {
            mp[i]++;
        }
        int count=mp.size();
        vector<int>ans;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
            {
                count--;
            }
            }
            
            
            
            if(j-i+1==len)
            {
                if(count==0)
                {
                    ans.push_back(i);
                }
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        count++;
                    }
                }
                i++;
            }
            j++;
            
        }
        return ans;
        
    }
};