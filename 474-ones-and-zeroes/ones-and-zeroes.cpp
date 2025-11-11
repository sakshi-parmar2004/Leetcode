class Solution {
public:
    int dp[601][101][101];
    int solve(int i,int m,int n,vector<string>& strs)
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
             op1= 1+solve(i+1,m-zero,n-ones,strs);
        }
        int op2 = solve(i+1,m,n,strs);
        return dp[i][m][n]= max(op1,op2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,strs);
        
    }
};