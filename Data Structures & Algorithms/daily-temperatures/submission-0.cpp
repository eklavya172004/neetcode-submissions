class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<pair<int,int>> st;

        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            if(st.empty()){
                result[i] = 0;
            }else{
                result[i] = st.top().second - i;
            }

            st.push({temperatures[i],i});
        }

        return result;
    }
};
