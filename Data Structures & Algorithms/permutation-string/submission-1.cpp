class Solution {
public:
   bool isFreqSame(int freq1[], int freq2[]) {

    for(int i = 0; i < 26; i++) {
        if(freq1[i] != freq2[i]) {
            return false;
        }
    }

    return true;
}

bool checkInclusion(string s1, string s2) {

    int freq[26] = {0};

    // frequency of s1
    for(int i = 0; i < s1.length(); i++) {
        freq[s1[i] - 'a']++;
    }

    int windSize = s1.length();

    // checking every window in s2
    for(int i = 0; i < s2.length(); i++) {

        int windIdx = 0;
        int idx = i;

        int windFreq[26] = {0};

        // create current window frequency
        while(windIdx < windSize && idx < s2.length()) {

            windFreq[s2[idx] - 'a']++;

            windIdx++;
            idx++;
        }

        // compare both frequency arrays
        if(isFreqSame(freq, windFreq)) {
            return true;
        }
    }

    return false;
}
};
