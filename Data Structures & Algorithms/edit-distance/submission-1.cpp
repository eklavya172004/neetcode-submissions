class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return minD(n,m,dp,word1,word2);
    }

    int minD(int i,int j,vector<vector<int>>& dp,string& w1,string& w2){
        if(i == 0) return j;
        if(j == 0) return i;

        if(dp[i][j] != -1) return dp[i][j];

        if(w1[i-1] == w2[j-1]){
            return dp[i][j] = minD(i-1,j-1,dp,w1,w2);
        }

        // insert
        int insert =   1 + minD(i,j-1,dp,w1,w2);

        // replace
        int replace =  1 + minD(i-1,j-1,dp,w1,w2);

        // delete
        int deleteop = 1 + minD(i-1,j,dp,w1,w2);
    
        return dp[i][j] = min({insert,replace,deleteop});
    }
};
