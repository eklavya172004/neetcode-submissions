class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(char c: s){
            mp1[c]++;
        }

        for(char m: t){
            mp2[m]++;
        }

        for(char c : s){
            if(mp1[c] != mp2[c]){
                return false;
            }
        }

        return true;
    }
};
