class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // vector<vector<int>> dp(n,vector<int>(amount+1,0));

    //     int ans = coin(n-1,dp,amount,coins);

    //     if(ans == 1e9){
    //         return -1;
    //     }

    //     return ans;
    // }   

    // int coin(int ind,vector<vector<int>>& dp,int target,vector<int>& coins){
    //     if(ind == 0){
    //         if(target % coins[ind] == 0) return target / coins[ind];
    //         else return 1e9;
    //     }
    //     if(dp[ind][target] != -1) return dp[ind][target];

    //     int notpick = coin(ind-1,dp,target,coins);

    //     int pick = 1e9;

    //     if(target >= coins[ind]){
    //         pick = 1 + coin(ind,dp,target-coins[ind],coins);
    //     }

    //     return dp[ind][target] = min(pick,notpick);
    // }

// tabulation
    // for(int target = 0 ; target <= amount ; target++){
    //     if(target % coins[0] == 0){
    //         dp[0][target] = target / coins[0];
    //     }else{
    //         dp[0][target] = 1e9;
    //     }
    // }

    // for(int i = 1 ; i < coins.size() ; i++){
    //     for(int t = 0 ; t <= amount ; t++){
        
    //     int notpick = dp[i-1][t];

    //     int pick = 1e9;

    //     if(t >= coins[i]){
    //         pick = 1 + dp[i][t-coins[i]];
    //     }

    //     dp[i][t] = min(notpick,pick);
    //     }
    // }

    //     int ans = dp[n-1][amount];

    //     return (ans >= 1e9) ? -1 : ans;

    // space optimization
        int prev[amount+1];
    
    for(int target = 0 ; target <= amount ; target++){
        if(target % coins[0] == 0){
            prev[target] = target / coins[0];
        }else{
            prev[target] = 1e9;
        }
    }

        for(int i = 1 ; i < coins.size() ; i++){
            for(int t = 0 ; t <= amount ; t++){
            
            int notpick = prev[t];

            int pick = 1e9;

            if(t >= coins[i]){
                pick = 1 + prev[t-coins[i]];
            }

            prev[t] = min(notpick,pick);
            }
    }

        int ans = prev[amount];

        return (ans >= 1e9) ? -1 : ans;

    }
};
