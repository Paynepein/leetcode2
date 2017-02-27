class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        int last = nums.size() - 1;
        for (int i = 0; i <= last; ++i) {
            if (nums[i] == val) {
                while (nums[last] == val) --last;
                if (last <= i) break;
                swap(nums[i], nums[last--]);
            }
        }
        return last+1;
    }
};