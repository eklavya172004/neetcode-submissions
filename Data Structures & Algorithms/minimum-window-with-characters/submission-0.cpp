class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        unordered_map<char,int> window;

        int l = 0;
        int r = 0;

        for(int i = 0 ; i < t.size() ; i++){
            need[t[i]]++;
        }

        int minL = INT_MAX;
        int start = 0;

        int matched = 0;
        int required = t.size();

        for(int r = 0 ; r < s.size() ; r++){
            window[s[r]]++;

            if(window[s[r]] <= need[s[r]]){
                matched++;
            }

            // shrinking
            while(matched == required){

                if(r - l + 1 < minL){
                    minL = r - l + 1;
                    start = l;
                }

                window[s[l]]--;
                if(window[s[l]] < need[s[l]]){
                    matched--;
                }
                l++;
            }
        }

        if(minL == INT_MAX)
            return "";

        return s.substr(start,minL);
    }
};
