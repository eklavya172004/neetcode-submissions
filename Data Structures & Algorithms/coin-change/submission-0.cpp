class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = coin(n-1,dp,amount,coins);

        if(ans == 1e9){
            return -1;
        }

        return ans;
    }   

    int coin(int ind,vector<vector<int>>& dp,int target,vector<int>& coins){
        if(ind == 0){
            if(target % coins[ind] == 0) return target / coins[ind];
            else return 1e9;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int notpick = coin(ind-1,dp,target,coins);

        int pick = 1e9;

        if(target >= coins[ind]){
            pick = 1 + coin(ind,dp,target-coins[ind],coins);
        }

        return dp[ind][target] = min(pick,notpick);
    }
};
