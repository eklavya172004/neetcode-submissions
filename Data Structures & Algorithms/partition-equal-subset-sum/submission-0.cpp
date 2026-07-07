class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sumTotal = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            sumTotal += nums[i];
        }

        if(sumTotal % 2 != 0)
        return false;

        int target = sumTotal / 2;

        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));

        return f(nums,target,dp,nums.size() - 1);
    }

    bool f(vector<int>& nums,int target,vector<vector<int>>& dp,int ind){
        if(target == 0) return true;

        if(ind == 0) return nums[0] == target;
    
        if(dp[ind][target] != -1) return dp[ind][target];

        bool take = false;

        if(target >= nums[ind]){
            take = f(nums,target-nums[ind],dp,ind-1);
        }

        bool nottake = f(nums,target,dp,ind-1);
   
        return dp[ind][target] = take || nottake;
    }
};