class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lmin = prices[0];
        int n = prices.size();

        int maxProfit = 0;

        for(int i = 1 ; i < n ; i++){
            lmin = min(lmin,prices[i]);

            maxProfit = max(maxProfit,prices[i] - lmin);
        }

        return maxProfit;
    }
};
