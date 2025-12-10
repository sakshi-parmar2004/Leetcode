class Solution {
public:
    int MOD= 1e9+7;
    int solve(int i,int j,int m,int n ,vector<vector<int>>& nums, int k,int rem,vector<vector<vector<int>>>&dp)
    {
        if(i>=m || j>=n )
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            if((rem+nums[i][j])%k==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][j][rem]!=-1)return dp[i][j][rem];

        int op1= solve(i+1,j,m,n,nums,k,(rem+nums[i][j])%k ,dp);
        int op2= solve(i,j+1,m,n,nums,k,(rem+nums[i][j])%k ,dp);
        return dp[i][j][rem] = (op1+op2)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& nums, int k) {
        int m=nums.size(),n=nums[0].size();
        // int dp[m][n][k];
        // memset(dp,-1,sizeof(dp));
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(0,0,m,n,nums,k,0,dp);
    }
};