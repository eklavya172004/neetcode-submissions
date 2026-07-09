class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();

       vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return coin(n-1,coins,dp,amount);
    }

    int coin(int i,vector<int>& nums,vector<vector<int>>& dp,int target){
        if(i == 0){
            if(target % nums[0] == 0) return 1;
            else return 0;
        }
        if(dp[i][target] != -1) return dp[i][target];

        int notpick = coin(i-1,nums,dp,target);

        int pick = 0;

        if(target >= nums[i]){
            pick = coin(i,nums,dp,target-nums[i]);
        }

        return dp[i][target] = pick + notpick ;
    }
};
