class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m=queries.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            int row_start=queries[i][0],col_start=queries[i][1]
            ,row_end=queries[i][2],col_end=queries[i][3];

            for(int p=row_start;p<=row_end;p++)
            {
                for(int q=col_start;q<=col_end;q++)
            {
                ans[p][q]++;
            }
            }
        
        }
        return ans;

        
    }
};