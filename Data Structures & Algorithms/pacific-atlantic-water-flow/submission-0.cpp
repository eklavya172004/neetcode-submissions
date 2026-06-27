class Solution {
public:
    void dfs(vector<vector<int>>& heights,int row,int col,vector<vector<bool>>& vis){
        vis[row][col] = true;
        int n = heights.size();
        int m = heights[0].size();

// up,down,left,right

        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

        for(int i = 0 ; i < 4 ; i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && heights[nrow][ncol] >= heights[row][col] && !vis[nrow][ncol]){
                dfs(heights,nrow,ncol,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantis(n,vector<bool>(m,false));

        // top row , first col
        for(int j = 0 ; j < m ; j++){
            // height,row,col,vis

            // top row
            // last row
                dfs(heights,0,j,pacific);
                dfs(heights,n-1,j,atlantis);
        }

        // first col
        // last col
        for(int i = 0 ; i < n ; i++){
            dfs(heights,i,0,pacific);
            dfs(heights,i,m-1,atlantis);
        }

    vector<vector<int>> result;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(pacific[i][j] && atlantis[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;   
    }
};
