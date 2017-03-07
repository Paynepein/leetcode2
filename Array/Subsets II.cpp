class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        for (int i = 0; i < nums.size();) {
        	int count = 0;
        	while (i + count < nums.size() && nums[i + count] == nums[i]) ++count;
        	int len = res.size();
        	for (int j = 0; j < len; ++j) {
        		vector<int> tmp = res[j];
        		for (int k = 0; k < count; ++k) {
        			tmp.push_back(nums[i]);
        			res.push_back(tmp);
        		}
        	}
        	i += count;
        }
        return res;
    }
};