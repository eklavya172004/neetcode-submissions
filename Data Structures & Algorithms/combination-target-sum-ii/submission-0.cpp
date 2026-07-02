class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

            vector<int> temp;
            sort(candidates.begin(),candidates.end());
// indx,{},target,candidates
           f(0,temp,target,candidates);

           return ans;
    }

    void f(int idx,vector<int>& curr,int t,vector<int>& nums){
        if(idx > nums.size()) return;
        if(t == 0){
            ans.push_back(curr);
            return;
        }
        if(t < 0){
            return;
        }

        for(int i = idx ; i < nums.size() ; i++){
            if(i>idx && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);

            f(i+1,curr,t-nums[i],nums);

            curr.pop_back();
        }
    }
};
