class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++)
        {

           int row_start=queries[i][0],col_start=queries[i][1]
            ,row_end=queries[i][2],col_end=queries[i][3];

            ans[row_start][col_start]++;
            if(row_end+1<n){
            ans[row_end+1][col_start]--;
            }
             if(col_end+1<n){
            ans[row_start][col_end+1]--;
             }
              if(row_end+1<n && col_end+1<n ){
            ans[row_end+1][col_end+1]++;
              }



        }

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                ans[i][j] += ans[i][j-1];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j] += ans[i-1][j];
            }
        }
        return ans;
    }
};