class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> pq;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0){
                    pq.push({i,j});
                }
            }
        }

        while(!pq.empty()){
            pair<int,int> t = pq.front();
            int r = t.first;
            int c = t.second;
            pq.pop();

    // up,down,left,right
            int dr[] = {-1,1,0,0};
            int dc[] = {0,0,-1,1};

            for(int i = 0 ; i < 4 ; i++){
                int nrow = dr[i] + r;
                int ncol = dc[i] + c;

                if(nrow >=0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 2147483647 ){
                    
                    grid[nrow][ncol] = grid[r][c] + 1;
                    pq.push({nrow,ncol});
                }
            }
        }
    }
};
