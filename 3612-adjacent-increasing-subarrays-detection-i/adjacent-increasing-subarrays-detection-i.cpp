class Solution {
public:
    bool solve(int i,int j,vector<int>& nums)
    {
        for(int ind= i+1;ind<=j;ind++)
        {
            if(nums[ind]<=nums[ind-1])
            {
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {

        for(int i=0;i<=nums.size()-2*k;i++)
        {
            if(solve(i,i+k-1,nums) && solve(i+k,i+2*k-1,nums))
            {
                return true;
            }
        }
        return false;
        
    }
};