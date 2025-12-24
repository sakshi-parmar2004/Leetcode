class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>arr(26,0);
        int n= cost.size();
        long long total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum += cost[i];
            arr[s[i]-'a']= arr[s[i]-'a']+cost[i];
        }

        long long mini=LLONG_MAX;
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)
            {
                continue;
            }
            mini= min(mini,total_sum-arr[i] );
        
        }
        return mini;
    }
};