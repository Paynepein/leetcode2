class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
  		vector<vector<int>> res;
  		combinationSum3Helper(1, n, k, vector<int>(0), res);
  		return res;
    }

    void combinationSum3Helper(int num, int remain, int k, vector<int> vec, vector<vector<int>>& res) {
    	if (remain < num || k <= 0 || num > 9) return;
    	if (remain == num) {
    		if (k == 1) {
    			res.push_back(vec);
    			res.back().push_back(num);
    		}
    		return;
    	}
    	vec.push_back(num);
    	combinationSum3Helper(num+1, remain - num, k-1, vec, res);
    	vec.pop_back();
    	combinationSum3Helper(num+1, remain, k, vec, res);
    }
};