class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = nums.size(), xxor = n;
        for (int i = 0; i < n; ++i) {
        	xxor ^= i ^ nums[i];
        }
        return xxor;
    }
};