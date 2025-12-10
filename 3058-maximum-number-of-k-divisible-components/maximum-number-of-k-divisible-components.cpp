class Solution {
public:
    void solve(int i,unordered_map<int,vector<int>>&adj_list,vector<int>&parent,stack<int>&st,vector<bool>&visited)
    {
        visited[i]=true;
        st.push(i);
        for(int nbr:adj_list[i])
        {
            if(visited[nbr])
            {
                continue;
            }
           parent[nbr]=i;
           solve(nbr,adj_list,parent,st,visited);
        }
       return ;
        

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        unordered_map<int,vector<int>>adj_list;
        vector<long long>sum(values.begin(),values.end());
        vector<int>parent(n);
        vector<bool>visited(n,false);
        stack<int>st;
        for(auto i:edges)
        {
            int u = i[0],v=i[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int count=0;
        solve(0,adj_list,parent,st,visited);
       
         while(!st.empty())
         {
             int node = st.top();
          if(sum[node]%k==0)
            {
                count++;
            }
            else
            {
                sum[parent[node]]+= sum[node];
            }
            st.pop();
         }
    
        
        return count;
        
        
    }
};