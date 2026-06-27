class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp1;
        vector<int> temp2;


        if(n==1) return nums[0];

        for(int i = 0 ; i < n ; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size(), -1);
        vector<int> dp2(temp2.size(), -1);

        return max(robber(temp1.size()-1,temp1,dp1),robber(temp2.size()-1,temp2,dp2));
    }

    int robber(int i,vector<int>& nums,vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        if(i == 0) return nums[i];
 
        int pick = robber(i-2,nums,dp) + nums[i];

        int notpick = robber(i-1,nums,dp);

        return dp[i] = max(pick,notpick);
    }
};
