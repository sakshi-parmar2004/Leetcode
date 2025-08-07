class Solution {
public:
    void solve(int i, unordered_map<int,list<int>>&mp , vector<int>&ans , vector<bool>&visited)
    {
        
        queue<int>q;
        q.push(i);
        visited[i]=true;
        while(!q.empty())
        {
            int front= q.front();
            q.pop();
            ans.push_back(front);
            
            for(int j:mp[front])
            {
                if(!visited[j])
                {
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {


        unordered_map<int,list<int>>mp;
        vector<int>ans;
        vector<bool>visited(arr.size()+1, false);
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                
                if(arr[i][j]==1)
                {
                    mp[i+1].push_back(j+1);
                }
                
            }
        }
        for(int i=1;i<=arr.size();i++)
        {
            if(!visited[i])
            {
                count++;
                solve(i,mp,ans ,visited);

            }
        }
        return count;
        
    }
};