class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0,ans=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};