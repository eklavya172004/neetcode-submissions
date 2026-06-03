class Solution {
public:
    void dfs(vector<vector<int>>& visited,
    int row,
    int col,
    vector<vector<char>>& Grid){
        int n = Grid.size();
        int m = Grid[0].size();
        visited[row][col] = 1;

//      up,down,left,right
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && Grid[nrow][ncol] == '1' && visited[nrow][ncol] == 0){
                dfs(visited,nrow,ncol,Grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

       vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    dfs(vis,i,j,grid);
                }
            }
        }

        return count;
    }
};
