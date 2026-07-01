class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        return sub({},nums,0,target);
    }

    vector<vector<int>> sub(vector<int> p,vector<int>& nums,int index,int target){
        if(target == 0){
            vector<vector<int>> list;
            list.push_back(p);
            return list;
        }

        if(index == nums.size()){
            return {};
        }

        vector<vector<int>> take;

        if(nums[index] <= target){
            vector<int> temp = p;

            temp.push_back(nums[index]);

            take = sub(temp,nums,index,target-nums[index]);
        }

        vector<vector<int>> nottake = sub(p,nums,index+1,target);

        take.insert(take.end(),nottake.begin(),nottake.end());

        return take;
    }
};
