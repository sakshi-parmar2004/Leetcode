
class Solution {
public:
    void solve(int i, vector<bool>& visited, unordered_map<int, vector<int>>& adj,
               unordered_map<int, set<int>>& mp, vector<int>& arr, int count) {
        queue<int> q;
        q.push(i);
        arr[i] = count;
        visited[i] = true;
        mp[count].insert(i);

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto neighbor : adj[front]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    mp[count].insert(neighbor);
                    arr[neighbor] = count;
                    visited[neighbor] = true;
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, set<int>> mp;
        unordered_map<int, vector<int>> adj;
        unordered_set<int> offline;
        vector<bool> visited(c + 1, false);
        vector<int> ans;
        vector<int> arr(c + 1, -1);

        for (auto& edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 1;
        for (int i = 1; i <= c; i++) {
            if (!visited[i]) {
                solve(i, visited, adj, mp, arr, count);
                count++;
            }
        }

        for (auto& query : queries) {
            if (query[0] == 2) {
                offline.insert(query[1]);
                int comp = arr[query[1]];
                mp[comp].erase(query[1]); // remove from component set
            } else {
                int node = query[1];
                int comp = arr[node];
                if(mp[comp].find(node)!=mp[comp].end())
                {
                      ans.push_back(node);
                }
                else{
                if (mp[comp].empty()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(*mp[comp].begin()); // smallest online node
                }
                }
            }
        }

        return ans;
    }
};


