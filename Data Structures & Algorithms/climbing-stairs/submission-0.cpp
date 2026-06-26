class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return climb(n,dp);
    }

    int climb(int i,vector<int>& dp){
        if(i == 0) return 1;
        if(i<0) return 0;
        if(dp[i] != -1) return dp[i];

        int one = 0;
        int two = 0;

        one = climb(i-1,dp);
        if(i>1) two = climb(i-2,dp);

        return dp[i] = one + two;
    }
};
