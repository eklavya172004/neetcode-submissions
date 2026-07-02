class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<int> path;

        permut(nums,path,vis);
        
        return ans;
    }

    void permut(vector<int>& nums,vector<int>& path,vector<bool>& vis){
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(vis[i]){
                continue;
            }

            vis[i] = true;
            path.push_back(nums[i]);

            permut(nums,path,vis);

            vis[i] = false;
            path.pop_back();
        }
    }
};
