class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < nums.size(); ++j) {
                if (j-1 > i && nums[j] == nums[j-1]) continue;
                int left = j+1, right = nums.size()-1, sum = target - nums[i] - nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < right && nums[left] == nums[left+1]) ++left;
                        while (right - 1 > left && nums[right-1] == nums[right]) --right;
                        ++left, --right;
                    } else if (nums[left] + nums[right] < sum) {
                        ++left;
                    } else {
                        --right;
                    }

                }
            }
        }
        return res;
    }
};