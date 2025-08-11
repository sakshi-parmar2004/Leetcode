class Solution {
public:
        vector<vector<int>>arr={{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int i,int j ,int color , vector<vector<int>>&ans, vector<vector<bool>>&visited,vector<vector<int>>&image,int m,int n)
    {

        visited[i][j]=true;
        ans[i][j]=color;
         for(int ind=0;ind<4;ind++)
            {
                int newi= i+ arr[ind][0];
                int newj= j+ arr[ind][1];

                if(newi>=0 && newj>=0 && newi<m && newj<n && !visited[newi][newj] && image[newi][newj]==image[i][j])
                {
                  dfs(newi,newj,color,ans,visited,image,m,n);
                }
            }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int m = image.size(), n = image[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n,false));
        

        dfs(sr,sc,color,ans,visited,image,m,n);
        // queue<pair<int,int>>q;
        // q.push({sr,sc});
        // ans[sr][sc]=color;
        // while(!q.empty())
        // {
        //     int a = q.front().first;
        //     int b = q.front().second;
        //     q.pop();

        //     for(int i=0;i<4;i++)
        //     {
        //         int newi= a+ arr[i][0];
        //         int newj= b+ arr[i][1];

        //         if(newi>=0 && newj>=0 && newi<m && newj<n && !visited[newi][newj] && image[newi][newj]==image[a][b])
        //         {
        //             q.push({newi,newj});
        //             visited[newi][newj]=true;
        //             ans[newi][newj]=color;
        //         }
        //     }
        // }
        return ans;



        
    }
};