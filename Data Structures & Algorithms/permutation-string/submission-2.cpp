class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(int i = 0 ; i < s1.size() ; i++){
            freq1[s1[i]-'a']++;
        }

        int l = 0 ;

        for(int r = 0 ; r < s2.size() ; r++){
            freq2[s2[r] - 'a']++;

            while((r-l+1) > s1.size()){
                freq2[s2[l] - 'a']--;
                l++;
            }

            if(freq1 == freq2) return true;
        }

        return false;
    }
};
