class Solution {
public:

    int solve(int i,int m,int n,vector<string>& strs,vector<vector<vector<int>>>&dp)
    {
        if(i>=strs.size())
        {
            return 0;
        }
        if(m==0 && n==0)
        {
           return 0;
        }
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int zero=0,ones=0;
        for(int j=0;j<strs[i].length();j++)
        {
            if(strs[i][j]=='0'){
            zero++;}
            else
            {
                ones++;
            }
        }
        int op1=0;
        if(m>=zero && n>=ones)
        {
             op1= 1+solve(i+1,m-zero,n-ones,strs,dp);
        }
        int op2 = solve(i+1,m,n,strs,dp);
        return dp[i][m][n]= max(op1,op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,strs,dp);
        
    }
};