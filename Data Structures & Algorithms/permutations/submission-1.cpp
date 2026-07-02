class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, vector<int>& nums) {

        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {

            // Choose
            swap(nums[index], nums[i]);

            // Explore
            solve(index + 1, nums);

            // Undo (Backtrack)
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        solve(0, nums);
        return ans;
    }
};