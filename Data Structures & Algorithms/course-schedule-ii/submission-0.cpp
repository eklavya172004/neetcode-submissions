class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);

        for(auto& edge : prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
            indeg[u]++;
       }

        // do toposort and if cycle exists then toposort array length < numOCurses
        // return false;
        queue<int> pq;

        for(int i = 0 ; i < numCourses ;i++){
            if(indeg[i] == 0){
                pq.push(i);
            }
        }

        vector<int> order;

        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            order.push_back(node);

            for(int nei : adj[node]){
                indeg[nei]--;

                if(indeg[nei] == 0){
                    pq.push(nei);
                }
            }
        }

        if(order.size() == numCourses){
            return order;
        }else {
            return {};
        }
    }
};
