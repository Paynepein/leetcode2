class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
    	vector<int> maxProduct(nums.size(), 0), minProduct(nums.size(), 0);
        maxProduct[0] = minProduct[1] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxProduct[i] = max(nums[i], max(maxProduct[i-1]*nums[i], minProduct[i-1]*nums[i]));
            minProduct[i] = min(nums[i], min(maxProduct[i-1]*nums[i], minProduct[i-1]*nums[i]));
            res = max(res, maxProduct[i]);
        }
        return res;
    }
};