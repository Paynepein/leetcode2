class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
  		unordered_map<int, int> mp;
  		for (int n : nums) ++mp[n];
  		vector<vector<int>> bucket(nums.size()+1, vector<int>());
  		for (auto it = mp.begin(); it != mp.end(); ++it) {
  			bucket[it->second].push_back(it->first);
  		}
  		vector<int> res;
  		for (int i = nums.size(); i > 0 && k; --i) {
  			if (bucket[i].size() != 0) {
  				int len = min(k, int(bucket[i].size()));
  				copy(bucket[i].begin(), bucket[i].begin() + len, back_inserter(res));
  				k -= len;
  			}
  		}
  		return res;
    }
};