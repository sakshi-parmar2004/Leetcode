class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>full_lakes;
        set<int>dry_days;
        int n = rains.size();
         vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            if(rains[i]==0)
            {
                dry_days.insert(i);
            }
            else
            {
                if(full_lakes.count(rains[i]))
                {
                    auto it= dry_days.upper_bound(full_lakes[rains[i]]);
                    if(it==dry_days.end())
                    {
                        return {};
                    }
                    ans[*it]=rains[i];
                    dry_days.erase(it);

                }
                full_lakes[rains[i]]=i;
                ans[i]=-1;
            }


        }
        return ans;
    }
};