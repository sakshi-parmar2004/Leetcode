class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int ans=-1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        n=n/2;
        for(int i=0;i<nums.size();i++)
        {
            if((i+1<nums.size() && nums[i]==nums[i+1]) || (i+2<nums.size()&&   nums[i]==nums[i+2]))
            {
                return nums[i];
            }

        }
        return 0;
    }
};