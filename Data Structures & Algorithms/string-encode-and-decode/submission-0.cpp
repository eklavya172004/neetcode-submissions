class Solution {
public:
    string encode(vector<string>& strs) {
        int n = strs.size();

        string result = "";

        for(int i = 0 ; i < n ; i++){
            int l = strs[i].size();

            result += to_string(l) + "#" + strs[i];
        }

        return result;
    }

    vector<string> decode(string s) {
        int i = 0;


        vector<string> result;

        while(i<s.size()){

        int j = i;
        
          while(s[j] != '#'){
            j++;
          }

          int len = stoi(s.substr(i,j-i));

          string curr = s.substr(j+1,len);

          i = j+len+1;

          result.push_back(curr);
        }

        return result;
    }
};
