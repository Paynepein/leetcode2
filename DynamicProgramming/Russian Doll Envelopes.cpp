class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
    	if (envelopes.size() == 0) return 0;
        auto comp = [](pair<int, int>& a, pair<int, int>& b) -> bool {
        	if (a.first == b.first) return a.second > b.second;
        	return a.first < b.first;
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> dp(envelopes.size(), 0);
        int res = 0;
        for (int i = 0; i < envelopes.size(); ++i) {
        	dp[i] = 1;
        	for (int j = 0; j < i; ++j) {
        		if (envelopes[j].second < envelopes[i].second) {
        			dp[i] = max(dp[i], dp[j] + 1);
        		}
        	}
        	res = max(res, dp[i]);
        }
        return res;
    }
};