class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
          
                maxi=max(maxi,nums[i]);
                mini=min(mini, nums[i]);
                
            
        }
        return (long long)(maxi-mini)*k;
        
    }
};