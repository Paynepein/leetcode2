class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.size() == 0) return 0;
        int res = 0, buy = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
        	if (prices[i] < buy) {
        		buy = prices[i];
        	} else if (res < prices[i] - buy) {
        		res = max(res, prices[i] - buy);
        	}
        }
        return res;
    }
};