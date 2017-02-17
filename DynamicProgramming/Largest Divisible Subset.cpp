class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
        vector<int> maxLength(nums.size(), 0), nextI(nums.size(), 0);
        int maxI = 0, maxlen = 0;
        for (int i = nums.size()-1; i >= 0; --i) {
        	for (int j = i; j < nums.size(); ++j) {
        		if (nums[j] % nums[i] == 0 && maxLength[j] + 1 > maxLength[i]) {
        			maxLength[i] = maxLength[j] + 1;
        			nextI[i] = j;
        		}
        	}
        	if (maxLength[i] > maxlen) {
        		maxlen = maxLength[i];
        		maxI = i;
        	}
        }
        vector<int> res;
        for (int i = 0; i < maxlen; ++i) {
        	res.push_back(nums[maxI]);
        	maxI = nextI[maxI];
        }
        return res;
    }
};