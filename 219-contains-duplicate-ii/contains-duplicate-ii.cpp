class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            if(mp.find(nums[j])!=mp.end())
            {
            return true;
            }
            mp[nums[j]]++;
        
            if(j-i+1>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                mp.erase(nums[i]);
                }
                i++;
            }
            j++;

        }
        return false;
        
    }
};