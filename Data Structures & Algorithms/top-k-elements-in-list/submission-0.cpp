class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;

//  not optimized approach
        // for(int i = 0 ; i < nums.size() ; i++){
        //     m[nums[i]]++;
        // }
        
        // brute force approach
        // vector<pair<int,int>>  ans(m.begin(),m.end());

        // // sort the map descending order
        // sort(ans.begin(),ans.end(),[](pair<int,int>& a,pair<int,int>& b){
        //     return a.second>b.second;
        // });

        // // take the top k elements
        // vector<int> result;

        // for(int i = 0 ; i < k ; i++){
        //     auto it = ans[i];
        //     result.push_back(it.first);
        // }

        // return result;

        // optimized approach
        for(int i = 0 ; i < nums.size() ; i++){
            m[nums[i]]++;
        }
    
        vector<vector<int>> bucket(nums.size()+1);

        for(auto it : m){
            bucket[it.second].push_back(it.first);
        }

        vector<int> result;
        int n = bucket.size();

        for(int i = n-1 ; i >= 0 ; i--){
            for(int num:bucket[i]){
                result.push_back(num);

                if(result.size() == k){
                    return result;
                }
            }
        }

        return result; 
    }
};
