class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        int count = 0;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                count++;
                dfs(vis,i,adj);
            }
        }
    
    return count;
    }

    void dfs(vector<int>& vis,int node,vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto &it : adj[node]){
            if(!vis[it]){
                dfs(vis,it,adj);
            }
        }
    }
};
