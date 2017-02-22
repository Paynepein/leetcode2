class Solution {
public:
    bool canCross(vector<int>& stones) {
    	if (stones.back() - stones[0] == 1) return true;
        unordered_map<int, set<int>> dp;
        dp[0].insert(1);
        for (int i = 0; i < stones.size()-1; ++i) {
        	for (int step : dp[stones[i]]) {
        		int reach = step + stones[i];
        		if (reach == stones.back()) return true;
        		dp[reach].insert(step);
        		if (step - 1 > 0) dp[reach].insert(step-1);
        		dp[reach].insert(step+1);
        	}
        }
        return false;
    }
};