class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0 ; i  < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        int anst = 0;

        while(!q.empty()){
            auto element = q.front();
            int row = element.first.first;
            int col = element.first.second;
            int t = element.second;
            q.pop();

            anst = max(anst,t);

            // up,down,left,right
            int drow[] = {-1,1,0,0};
            int dcol[] = {0,0,-1,1};

            for(int i = 0 ; i < 4 ; i++){
                int nrow = drow[i] + row;
                int ncol = dcol[i] + col;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol] == 1
                ){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},t+1});
                }
            }
        }

                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return anst;
    }
};
