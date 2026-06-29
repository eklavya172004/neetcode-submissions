class Solution {
public:
    bool validTree(int n,vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }

        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);

        for(auto& it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,vis,adj);

        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }

    void dfs(int node,vector<bool>& vis,vector<vector<int>>& edges){
        vis[node] = true;

        for(int no : edges[node]){
            if(!vis[no]){
                dfs(no,vis,edges);
            }
        }
    }
};