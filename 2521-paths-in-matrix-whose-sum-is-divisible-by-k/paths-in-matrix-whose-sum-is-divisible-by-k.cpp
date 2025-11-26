class Solution {
public:
    int MOD= 1e9+7;
    int solve(int i,int j,int sum,vector<vector<int>>& grid, int k, vector<vector<vector<int>>>&dp)
    {
        if(i>=grid.size() || j>=grid[0].size())
        {
            return 0;
        }
        
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if((sum+grid[i][j]) %k==0)
            {
                return 1;
            }
            return 0;
           
        }
        if(dp[i][j][sum]!=-1)
        {
            return dp[i][j][sum];
        }

        int op1 = solve(i+1,j,(sum+grid[i][j])%k,grid,k,dp);
        int op2= solve(i,j+1,(sum+grid[i][j])%k,grid,k,dp);
        return dp[i][j][sum]= (op1+op2)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m= grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));

        return solve(0,0,0,grid,k,dp);
    }
};