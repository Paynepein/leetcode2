class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int dp = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp = nums[i] + max(0, dp);
            res = max(res, dp);
        }
        return res;
    }
};