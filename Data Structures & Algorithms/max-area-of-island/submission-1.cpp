class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxArea = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 1 && grid[i][j] == 1){
                    int count = 1;
                    findarea(vis,grid,i,j,count);

                    maxArea = max(maxArea,count);
                }
            }
        }

        return maxArea;        
    }

    void findarea(vector<vector<int>>& vis,vector<vector<int>>& grid,int row,int col,int& count){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        // up,down,left,right
        int drow[4] = {-1,1,0,0};
        int dcol[4] = {0,0,-1,1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                count++;
                findarea(vis,grid,nrow,ncol,count);
            }
        } 
    }
};
