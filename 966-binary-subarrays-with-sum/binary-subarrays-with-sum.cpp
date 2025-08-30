class Solution {
public:
    int solve(int i,vector<int>& nums, int goal)
    {
        if(goal<0)
        {
            return 0;
        }
        int ans=0 ,j=0,sum=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            while(sum>goal)
            {
                sum-=nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        int value1= solve(0,nums,goal);
        int value2 = solve(0,nums,goal-1);
        return value1-value2;
    }
};