class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int i=0,j=0, n= s.length() , len=INT_MAX,ans=0;
        for(char i:t)
        {
            mp[i]++;
        }
        int count=mp.size();
        while( j<n )
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
            }
            
            while(count==0)
            {
             if(j-i+1<len)
             {
                ans= i;
                len=j-i+1;
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
        if(len==INT_MAX)return "";
        return s.substr(ans,len);
        
    }
};