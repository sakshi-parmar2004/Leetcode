class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<char,long long>mp;
        int n= cost.size();
        long long total_sum=0;
        for(int i=0;i<n;i++)
        {
            total_sum += cost[i];
            mp[s[i]]+=cost[i];
        }

        long long mini=LLONG_MAX;
        for(auto i:mp)
        {
            mini= min(mini,total_sum-i.second );
        
        }
        return mini;
    }
};