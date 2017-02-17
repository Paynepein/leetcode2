class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    	if (matrix.size() == 0) return 0;
    	int m = matrix.size(), n = matrix[0].size();
        int res = INT_MIN;
        for (int left = 0; left < n; ++left) {
        	vector<int> sum(m, 0);
        	for (int right = left; right < n; ++right) {
        		for (int i = 0; i < m; ++i) {
        			sum[i] += matrix[i][right];
        		}
        		set<int> myset;
        		myset.insert(0);
        		int curSum = 0, tmpMax = INT_MIN;
        		for (int num : sum) {
        			curSum += num;
        			auto it = myset.lower_bound(curSum - k);
        			if (it != myset.end()) tmpMax = max(tmpMax, curSum - *it);
        			myset.insert(curSum);
        		}
        		res = max(res, tmpMax);
        	}
        }
        return res;
    }
};