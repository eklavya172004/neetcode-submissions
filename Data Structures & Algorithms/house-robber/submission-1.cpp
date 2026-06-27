class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,-1);

        return robber(n-1,nums,dp);
    }

    int robber(int i,vector<int>& nums,vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        if(i == 0) return nums[i];

        int pick = 0;
 
        pick = robber(i-2,nums,dp) + nums[i];

        int notpick = robber(i-1,nums,dp);

        return dp[i] = max(pick,notpick);
    }
};
