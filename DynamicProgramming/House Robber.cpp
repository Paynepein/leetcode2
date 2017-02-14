class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int one = 0, two = nums[0], here = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
        	here = max(one + nums[i], two);
        	one = two;
        	two = here;
        }
        return here;
    }
};