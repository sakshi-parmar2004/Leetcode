class Solution {
public:
    int numSub(string s) {
        long long count=0,ans=0,MOD=1e9+7;
        for(int i=0;i<s.length();i++)
        {
           
                if(s[i]=='0')
                {
                    ans+= (((count)*(count+1))/2)%MOD;
                    count=0;
                    continue;
                }
                count++;
                count= count%MOD;
                

        }
             ans+= (((count)*(count+1))/2)%MOD;
         return ans%MOD;
        
    }
};