class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0 ;
        int j = n-1;
        int maxArea = INT_MIN;

        while(i<j){
            int w = j-i;
            int l = min(heights[i],heights[j]);

            maxArea = max(maxArea,w*l);

            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }
        }

        return maxArea;
    }
};
