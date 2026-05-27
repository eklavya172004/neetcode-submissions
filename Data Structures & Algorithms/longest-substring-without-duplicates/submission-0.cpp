class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;

        map<char,int> st;

        while(r < n) {

            if(st.find(s[r]) != st.end() && st[s[r]] >= l) {
                l = st[s[r]] + 1;
            }

            st[s[r]] = r;

            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};
