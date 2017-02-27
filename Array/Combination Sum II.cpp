class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, 0, target, vector<int>(0), res);
        return res;
    }

    void combinationSumHelper(vector<int>& candidates, int index, int target, vector<int> tmp, vector<vector<int>>& res) {
    	for (int i = index; i < candidates.size() && candidates[i] <= target; ++i) {
    		if (i == index || candidates[i] != candidates[i-1]) {
    			if (candidates[i] == target) {
    				tmp.push_back(candidates[i]);
    				res.push_back(tmp);
    				return;
    			} else {
    				tmp.push_back(candidates[i]);
    				combinationSumHelper(candidates, i+1, target - candidates[i], tmp, res);
    				tmp.pop_back();
    			}
    		}
    	}
    }
};