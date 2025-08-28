class Solution {
public:
    int solve(int a,int b)
    {
        int ans=a;
        while(b>0)
        {
    
            int bit_of_b = b&1;
            //ooposite bits as b is 1 bits the ans and a will have opp bit in this case
            if(bit_of_b!=0)
            {
                 ans=ans^1;
            }
            
            b>>1;
            1<<1;

        }
        return ans;
    }
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        vector<int>ans(n);
        ans[0]=pref[0];
        for(int i=1;i<pref.size();i++)
        {
            ans[i]= pref[i-1]^pref[i];
        }
        
        return ans;
    }
};