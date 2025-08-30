class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0,sum=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==goal)
            {
                count++;
            }
            int value = sum-goal;
            if(mp.find(value)!=mp.end())
            {
                count+=mp[value];
            }
            mp[sum]++;
        }
        return count;
        
    }
};