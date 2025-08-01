class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        int count=0 , sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                count++;
            }

            int val = sum-k;
            if(mp.find(val)!=mp.end())
            {
                count+= mp[val];
            }
            mp[sum]++;

        }
        return count;
    }
};