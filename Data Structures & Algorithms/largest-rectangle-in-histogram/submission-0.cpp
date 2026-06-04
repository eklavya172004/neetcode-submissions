class Solution {
public:
    vector<int> getpse(vector<int>& heights) {
    int n = heights.size();

    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }

    return pse;
    }

    vector<int> getnse(vector<int>& heights) {
    int n = heights.size();

    vector<int> nse(n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }

    return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int area = 0;

        vector<int> nse = getnse(heights);
        vector<int> pse = getpse(heights);

        for(int i = 0 ; i < heights.size() ; i++){
            int currArea = (nse[i] - pse[i] - 1) * heights[i];
            area = max(area, currArea);
        }

        return area;
    }
};
