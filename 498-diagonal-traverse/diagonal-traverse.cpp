class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int,vector<int>>mp;
        vector<int>ans;
        int row = mat.size() , col= mat[0].size();
         
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }

        for(auto &i:mp)
        {
            if(i.first%2==0)
          {  reverse(i.second.begin(),i.second.end());}
          
          for(int j:i.second)
          {
            ans.push_back(j);
          }
        }
        return ans;
    }
};