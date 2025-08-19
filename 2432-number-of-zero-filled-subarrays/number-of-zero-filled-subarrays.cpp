class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long n = nums.size(),i=0,j=0,ans=0;
        while(j<n)
        {
            if(nums[j]==0)
            {
                i=j;
                while(j<n && nums[j]==0)
                {
                    ans+=(j-i+1);
                    j++;
                }
            }
            j++;

        }
        return ans;
    }
};