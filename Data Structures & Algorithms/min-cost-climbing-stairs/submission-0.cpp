class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n,-1);

        return min(minCost(n-2,dp,cost),minCost(n-1,dp,cost));
    }

    int minCost(int i,vector<int>& dp,vector<int>& cost){
        if(i <= 1) return cost[i];
        if(i<0) return INT_MAX/2;
        if(dp[i] != -1) return dp[i];

        int jump2 = INT_MAX;
        
        int jump1 = cost[i] + minCost(i-1,dp,cost);
        if(i>1) jump2 = cost[i] + minCost(i-2,dp,cost);

        return dp[i] = min(jump1,jump2);
    }
};
