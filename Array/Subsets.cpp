class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
  		vector<vector<int>> res;
  		res.push_back(vector<int>());
  		for (int num : nums) {
  			int size = res.size();
  			for (int i = 0; i < size; ++i) {
  				vector<int> tmp = res[i];
  				tmp.push_back(num);
  				res.push_back(tmp);
  			}
  		}
  		return res;
    }
};