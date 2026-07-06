
class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n,vector<bool>(n,false));

        solve(board,0);

        return ans;
    }

    void solve(vector<vector<bool>>& bd,int row){
        if(row == bd.size()){
            display(bd);
            return;
        }

        for(int col = 0 ; col < bd[0].size() ; col++){
            if(isSafe(bd,row,col)){
                bd[row][col] = true;

                solve(bd,row+1);

                bd[row][col] = false;
            }
        }
    }

    void display(vector<vector<bool>>& bd){
        vector<string> board;

        for(int i = 0 ; i < bd.size() ; i++){
            string row = "";

            for(int j = 0 ; j < bd[0].size() ; j++){

                if(bd[i][j]){
                    row += 'Q';
                }else{
                    row += '.';
                }

            }

            board.push_back(row);
        }   
        
        ans.push_back(board);
    }

    bool isSafe(vector<vector<bool>>& bd,int row,int col){
        for(int it = 0 ; it < row ; it++){
            if(bd[it][col]){
                return false;
            }
        }

        // r--,c-- -> Upper-left diagonal
        int ln = min(row,col);

        int r = row-1;
        int c = col-1;

        for(int i = 0 ; i < ln ; i++){
            if(bd[r][c]){
                return false;
            }

            r--;
            c--;
        }

        //r--,c++ -> Upper-right diagonal
        int rn = min((int)bd[0].size() - col - 1,row);

        r = row-1;
        c = col+1;

        for(int i = 0 ; i < rn ; i++){
            if(bd[r][c]){
                return false;
            }

            r--;
            c++;
        }

        return true;
    }

};