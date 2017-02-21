class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
        vector<int> big(nums.size(), 1);
        vector<int> small(nums.size(), 1);
        int res = 1;
        for (int i = 1; i < nums.size(); ++i) {
        	for (int j = 0; j < i; ++j) {
        		if (nums[j] > nums[i]) {
        			small[i] = max(small[i], big[j] + 1);
        		} else if (nums[j] < nums[i]) {
        			big[i] = max(big[i], small[j] + 1);
        		}
        	}
        	res = max(res, max(big[i], small[i]));
        }
        return res;
    }
};