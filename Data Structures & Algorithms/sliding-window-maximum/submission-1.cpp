class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> result;
        
        for(int i = 0 ; i <= n-k ; i++){
            int maxL = nums[i];

            for(int j = i ; j < i+k ; j++){
                maxL = max(maxL,nums[j]);
            }

            result.push_back(maxL);
        }

        return result;
    }
};
