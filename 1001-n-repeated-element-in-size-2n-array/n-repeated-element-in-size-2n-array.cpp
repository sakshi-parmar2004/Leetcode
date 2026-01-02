class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans=-1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        n=n/2;
        for(int i=0;i<nums.size();i++)
        {
            if(i+n-1>nums.size())
            {
                   break;
            }
            if(nums[i]==nums[i+n-1])
           {
            return nums[i];
           }

        }
        return ans;
    }
};