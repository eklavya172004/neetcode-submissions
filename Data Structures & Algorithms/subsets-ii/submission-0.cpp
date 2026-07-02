class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> outer;
        sort(nums.begin(), nums.end());

        outer.push_back(vector<int>());

        int s = 0;
        int e = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            int n = outer.size();


            if(i>0 && nums[i] == nums[i-1]){
                s = e+1;
            }else{
                s = 0 ;
            }

            e = n-1;

            for(int j = s ; j < n ; j++){
                vector<int> temp = outer[j];
                temp.push_back(nums[i]);
                outer.push_back(temp);
            }
        }

        return outer;
    }
};
