class Solution {
public:
    int m,n;
    int MOD= 1e9+7;
    int dp[501][501][3];
    int solve(int i,int j,int dir, vector<vector<int>>& grid)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j][dir]!=-1)return dp[i][j][dir];
        int ans =0;
        if(grid[i][j]==0)
        {
           ans+=solve(i+1,j,2,grid)+solve(i,j+1,1,grid);
        }
        // if the direction was right to it will be turned down and the direction wil become 2
        else if(dir==1)
        {
            ans += solve(i+1,j,2,grid);
        }
         // if the direction was down to it will be turned right and the direction wil become 1
        else
        {
            ans += solve(i,j+1,1,grid);
        }
        return dp[i][j][dir]= ans % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        memset(dp,-1, sizeof(dp));
        return solve(0,0,0,grid);
        
    }
};