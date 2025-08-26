class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int i=0,j=0 ,n=s.length(), ans=INT_MIN,t=0;
        while(j<n)
        {
            if(s[j]=='T')
            {
                t++;
            }

            if(min(j-i+1-t,t)<=k )
            {
                ans=max(ans,j-i+1);
            }
            else
            {
                if(s[i]=='T')
                {
                    t--;
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};