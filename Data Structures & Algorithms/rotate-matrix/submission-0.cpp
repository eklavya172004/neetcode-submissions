class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0 ; i < n ; i++){
            reverseRow(matrix,i,n);
        }
    }

    void reverseRow(vector<vector<int>>& grid,int row,int m){
        int i = 0 ;
        int j = m-1;

        while(i<j){
          swap(grid[row][i], grid[row][j]);
            i++;
            j--; 
        }
    }
};
