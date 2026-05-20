class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int n = strs.size();
        vector<vector<string>> result;

        for(int i = 0 ; i < n; i++){
            int freq[26] = {0};
            
            string temp = strs[i];

            for(int j = 0 ; j < temp.size() ; j++){
                freq[temp[j] - 'a']++;
            }

            string news = "";

            for(int k = 0 ; k < 26 ; k++){
                int f = freq[k];
                if(f > 0){
                 // add this char to the string news
                    news += string(f,k+'a');
                }
            }

            mp[news].push_back(strs[i]);
        }

        for(auto it: mp){
            result.push_back(it.second);
        }

        return result;
    }
};
