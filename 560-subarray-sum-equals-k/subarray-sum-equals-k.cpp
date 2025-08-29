class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if( sum==k)count++;
            int value = sum-k;
            if(mp.find(value)!=mp.end())
            {
                count+= mp[value];
            }
            mp[sum]++;
        }
        return count;
        
    }
};