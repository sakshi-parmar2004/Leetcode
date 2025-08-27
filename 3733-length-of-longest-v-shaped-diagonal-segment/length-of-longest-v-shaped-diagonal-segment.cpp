class Solution {
public:
    int m,n;
   vector<vector<int>>arr;
   int solve(int i,int j,int dir,int value,bool turn)
        {
            if(i<0 || j<0 || i>=m || j>=n || arr[i][j]!=value)
            {
                return 0;
            }
           int ans=0;
            //option1 direction is towards to bottom right
            if(dir==0)
            {
                   ans= 1+ solve(i+1,j+1,dir,2-value,turn);
                   if(!turn)
                   {
                    ans=max(ans, 1+solve(i+1,j-1,1,2-value,!turn));
                   }
            }
            //option2 direction is towards to bottom left
            if(dir==1)
            {
                   ans= 1+ solve(i+1,j-1,dir,2-value,turn);
                   if(!turn)
                   {
                    ans=max(ans, 1+solve(i-1,j-1,2,2-value,!turn));
                   }
            }
           //option3 direction is towards to top left
            if(dir==2)
            {
                   ans= 1+ solve(i-1,j-1,dir,2-value,turn);
                   if(!turn)
                   {
                    ans=max(ans, 1+solve(i-1,j+1,3,2-value,!turn));
                   }
            }
            //option4 direction is towards to top right
            if(dir==3)
            {
                   ans= 1+ solve(i-1,j+1,dir,2-value,turn);
                   if(!turn)
                   {
                    ans=max(ans, 1+solve(i+1,j+1,0,2-value,!turn));
                   }
            }

            return ans;


        }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        arr=grid;
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,1+ solve(i+1,j+1,0,2,false));
                    ans=max(ans,1+ solve(i+1,j-1,1,2,false));
                    ans=max(ans,1+ solve(i-1,j-1,2,2,false));
                    ans=max(ans,1+ solve(i-1,j+1,3,2,false));

                }
            }
        }
        return ans;
        
    }
};