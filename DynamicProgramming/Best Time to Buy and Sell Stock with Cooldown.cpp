class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() == 0) return 0;
        vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
        buy[0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
        	sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        	buy[i] = max(buy[i-1], (i == 1 ? 0 : sell[i-2]) - prices[i]);
        }
        return sell[prices.size()-1];
    }
};