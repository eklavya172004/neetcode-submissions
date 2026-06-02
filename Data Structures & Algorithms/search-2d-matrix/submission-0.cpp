class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // flatten it into 1 d matrix
        int i = 0;
        int j = m*n-1;

        while(i <= j){
            int mid = i + (j-i) / 2;

            int row = mid/m;
            int col = mid%m;

            if(matrix[row][col] == target){
                return true;
            }

            if(matrix[row][col] > target){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }

        return false;
    }
};
