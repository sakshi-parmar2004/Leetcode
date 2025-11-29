class Solution {
public:
    void solve(int i,vector<int>&parent,vector<bool>&visited,stack<int>&st,unordered_map<int,vector<int>>&adj)
    {
        visited[i]=true;
        st.push(i);
        for(int j:adj[i])
        {
            if(visited[j])
            {
                continue;
            }
            parent[j]=i;
            solve(j,parent,visited,st,adj);
        }
        return ;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        stack<int>st;
        vector<bool>visited(n,false);
        vector<int>parent(n);
        parent[0]=-1;
        unordered_map<int,vector<int>>adj;
        for(auto i:edges)
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(0,parent,visited,st,adj);
        int ans=0;
        vector<long long>sum(values.begin(),values.end());
        while(!st.empty())
        {
           long long val = st.top();
           st.pop();
           if(sum[val]%k==0)
           {
            ans++;
           }
           else
           {
             sum[parent[val]]+= sum[val];
           }
        }
        return ans;
        
    }
};