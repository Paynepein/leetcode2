class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size()-1; i > 0; --i) {
        	if (nums[i] > nums[i-1]) {
        		int j = i+1;
        		for (; j < nums.size(); ++j) {
        			if (nums[j] <= nums[i-1]) {
        				break;
        			}
        		}
        		swap(nums[i-1], nums[j-1]);
        		sort(nums.begin() + i, nums.end());
        		return;
        	}
        }
        sort(nums.begin(), nums.end());
    }
    void nextPermutation(vector<int>& nums) {
        int left = nums.size()-1, right = left;
        while (left > 0) {
        	if (nums[left] > nums[left-1]) {
        		break;
        	}
        	--left;
        }
        if (left == 0) {
        	reverse(nums.begin(), nums.end());
        } else {
        	while (nums[right] <= nums[left-1]) {
        		--right;
        	}
        	swap(nums[left-1], nums[right]);
        	reverse(nums.begin() + left, nums.end());
        }
    }
};