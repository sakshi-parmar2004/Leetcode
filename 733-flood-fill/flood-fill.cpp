class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int m = image.size(), n = image[0].size();

        vector<vector<int>>arr={{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        
        queue<pair<int,int>>q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        while(!q.empty())
        {
            int a = q.front().first;
            int b = q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int newi= a+ arr[i][0];
                int newj= b+ arr[i][1];

                if(newi>=0 && newj>=0 && newi<m && newj<n && !visited[newi][newj] && image[newi][newj]==image[a][b])
                {
                    q.push({newi,newj});
                    visited[newi][newj]=true;
                    ans[newi][newj]=color;
                }
            }
        }
        return ans;



        
    }
};