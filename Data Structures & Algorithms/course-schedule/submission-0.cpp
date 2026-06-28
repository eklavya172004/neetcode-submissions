class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int count = 0 ;

        while(!pq.empty()){
            int node = pq.front();
            pq.pop();
            count++;

            for(int nei : adj[node]){
                indeg[nei]--;

                if(indeg[nei] == 0){
                    pq.push(nei);
                }
            }
        }

        return count == numCourses;
    }
};
