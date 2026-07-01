class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        return sub({},nums,0);
    }

    vector<vector<int>> sub(vector<int> p,vector<int>& nums,int index){
        if(index == nums.size()){
            vector<vector<int>> list;
            list.push_back(p);
            return list;
        }

        vector<int> take = p;
        take.push_back(nums[index]);

        vector<vector<int>> takeit = sub(take,nums,index+1);
        vector<vector<int>> nottakeit = sub(p,nums,index+1);

        takeit.insert(takeit.end(),nottakeit.begin(),nottakeit.end());

        return takeit;
    }
};
