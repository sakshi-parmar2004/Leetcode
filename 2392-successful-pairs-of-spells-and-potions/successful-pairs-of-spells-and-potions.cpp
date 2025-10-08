class Solution {
public:
    int bin_search(int l,int r,int i,vector<int>& spells, vector<int>& potions, long long success)
    {
        int ans=r+1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;

            long long prod =(long long)spells[i]*potions[mid];
            if(prod>=success)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {   
           int j = bin_search(0,m-1, i,spells,potions,success);
           ans[i]=(m-j);        
        }
        return ans;
        
    }
};