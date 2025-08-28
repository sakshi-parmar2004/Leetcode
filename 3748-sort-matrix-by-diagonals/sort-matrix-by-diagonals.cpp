class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        unordered_map<int,vector<int>>mp;
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i-j].push_back(grid[i][j]);

            }

            }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i-j>=0)
                {
                    sort(mp[i-j].begin(),mp[i-j].end(), greater<int>());
                }
                else
                {
                    sort(mp[i-j].begin(),mp[i-j].end());
                }

            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                ans[i][j] = mp[i-j].back();
                mp[i-j].pop_back();

            }

            }

            return ans;
        

        

        
    }
};