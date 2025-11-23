class Solution {
public:
    
    int solve(int i, vector<int>& nums, int rem,vector<vector<int>>&dp) {
      
        if (i >= nums.size()){
            if(rem==0)
            {
                return 0;
            }
            return INT_MIN;
       }
       if(dp[i][rem]!=-1)
       {
          return dp[i][rem];
       }
        int op1=solve(i + 1, nums, rem,dp);
        int op2=nums[i]+solve(i + 1, nums, (rem + nums[i])%3,dp);
        return dp[i][rem]= max(op1,op2);
      
    }
    int maxSumDivThree(vector<int>& nums) {
        int rem = 0;
        vector<vector<int>>dp(nums.size(),vector<int>(3,-1));
        return solve(0, nums, rem,dp);
        
    }
};