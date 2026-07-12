class Solution {
public:
    int countSubstrings(string s) {
       int n = s.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                if(solve(i,j,dp,s)){
                        count++;
                    }
                }
            }
        

        return count;
    }

    int solve(int i,int j,vector<vector<int>>& dp,string& s){
        if(i>= j){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1,j-1,dp,s);
        }

        return dp[i][j] = 0;
    }
};
