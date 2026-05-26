class Solution {
public:
    int trap(vector<int>& height) {
        // min(leftmax,rightmax) * height[i];
        int n = height.size();

        vector<int> prefix(n,0);

        prefix[0] = height[0];

        for(int i = 1 ; i < n ; i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }

        vector<int> suffix(n,0);
        suffix[n-1] = height[n-1];

        for(int i = n - 2; i >= 0 ; i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }

        int result = 0;

        for(int i = 0 ; i < n ; i++){
            if(height[i] < suffix[i] && height[i] < prefix[i]){
                result +=( min(suffix[i],prefix[i]) - height[i]);
            }
        }

        return result;
    }
};
