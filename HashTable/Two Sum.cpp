class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> res(2, 0);
        for (int i = 0; i < nums.size(); ++i) {
        	if (mp.find(nums[i]) != mp.end()) {
        		res[0] = mp[nums[i]];
        		res[1] = i;
        		break;
        	} else {
        		mp[target - nums[i]] = i;
        	}
        }
        return res;
    }
};