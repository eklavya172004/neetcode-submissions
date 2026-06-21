class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(auto &it : points){
            int x = it[0];
            int y = it[1];

            int d = x*x + y*y ;

            pq.push({d,{x,y}});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while(!pq.empty()){
            auto it = pq.top();
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();

            ans.push_back({row,col});
        }

        return ans;
    }
};
