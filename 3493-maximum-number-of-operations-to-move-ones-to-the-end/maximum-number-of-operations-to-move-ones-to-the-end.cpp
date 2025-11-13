class Solution {
public:
    int maxOperations(string s) {
        int ans=0,ones=0;
        int n= s.length();
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0' && s[i+1]=='1'){ans+=ones;}

            if(s[i]=='1')ones++;
        }
        if(s[n-1]=='0')ans += ones;
        return ans;
        
    }
};