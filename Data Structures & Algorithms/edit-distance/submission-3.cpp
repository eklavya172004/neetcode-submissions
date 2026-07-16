class Solution {
public:
    int minDistance(string word1, string word2) {
        // int n = word1.size();
        // int m = word2.size();

        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    //     return minD(n,m,dp,word1,word2);
    // }

    // int minD(int i,int j,vector<vector<int>>& dp,string& w1,string& w2){
    //     if(i == 0) return j;
    //     if(j == 0) return i;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(w1[i-1] == w2[j-1]){
    //         return dp[i][j] = minD(i-1,j-1,dp,w1,w2);
    //     }

    //     // insert
    //     int insert =   1 + minD(i,j-1,dp,w1,w2);

    //     // replace
    //     int replace =  1 + minD(i-1,j-1,dp,w1,w2);

    //     // delete
    //     int deleteop = 1 + minD(i-1,j,dp,w1,w2);
    
    //     return dp[i][j] = min({insert,replace,deleteop});
        
        // when i = 0
        // for(int j = 0 ; j <= m ; j++){
        //     dp[0][j] = j;
        // }

        // // when j = 0 
        // for(int i = 0 ; i <= n ; i++){
        //     dp[i][0] = i;
        // }

        // for(int i = 1 ; i <= n ; i++){
        //     for(int j = 1 ; j <= m ; j++){
        //         if(word1[i-1] == word2[j-1]){
        //             dp[i][j] = dp[i-1][j-1];
        //         }else{
        //         int insert =   1 + dp[i][j-1];

        //         // replace
        //         int replace =  1 + dp[i-1][j-1];

        //         // delete
        //         int deleteop = 1 + dp[i-1][j];
            
        //         dp[i][j] = min({insert,replace,deleteop});
        //         }
        //     }
        // }

        // return dp[n][m];

        int n = word1.size();
        int m = word2.size();



        vector<int> prev(m+1,0),curr(m+1,0);

        for(int j = 0 ; j <= m ; j++){
            prev[j] = j;
        }
        
        // when j = 0 
 
        // prev[0] = i;
        

        for(int i = 1 ; i <= n ; i++){
            
            curr[0] = i;
            
            for(int j = 1 ; j <= m ; j++){

                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1];
                }else{
                int insert =   1 + curr[j-1];

                // replace
                int replace =  1 + prev[j-1];

                // delete
                int deleteop = 1 + prev[j];
            
                curr[j] = min({insert,replace,deleteop});
                }

            }
            prev = curr;
        }

        return prev[m];
    }
};
