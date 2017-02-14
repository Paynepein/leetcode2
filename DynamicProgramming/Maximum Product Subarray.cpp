class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
        int maxPre = nums[0], minPre = maxPre, maxHere, minHere, res = maxPre;
        for (int i = 1; i < nums.size(); ++i) {
        	maxHere = max(maxPre * nums[i], max(minPre * nums[i], nums[i]));
        	minHere = min(maxPre * nums[i], min(minPre * nums[i], nums[i]));
        	maxPre = maxHere;
        	minPre = minHere;
        	res = max(res, maxHere);
        }
        return res;
    }
};