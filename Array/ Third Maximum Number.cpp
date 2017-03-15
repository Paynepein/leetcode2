class Solution {
public:
    int thirdMax(vector<int>& nums) {
  		set<int> big;
  		for (int num : nums) {
  			big.insert(num);
  			if (big.size() > 3) big.erase(big.begin());
  		}
  		if (big.size() < 3) return *(big.rbegin());
  		return *(big.begin());
    }
};