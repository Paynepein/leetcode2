class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<long> dp1(nums.size()+1, 0), dp2(nums.size()+1, 0), *ptr1 = &dp1, *ptr2 = &dp2;
        for (int i = 1; i <= m; ++i) {
        	ptr1->clear();
        	for (int j = 0; j <= nums.size()-i; ++j) {
        		long sum = 0, tmp = INT_MAX;
        		for (int k = j; k <= nums.size()-i; ++k) {
        			sum += nums[k];
        			tmp = min(tmp, max(sum, (*ptr2)[k+1]));
        		}
        		(*ptr1)[j] = tmp;
        	}
        	swap(ptr1, ptr2);
        }
        return (*ptr2)[0];
    }
};