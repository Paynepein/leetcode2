class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int value = nums[0], count = 1;
        for (int i = 1; i <= nums.size(); ++i) {
        	if (count == 0) {
        		value = nums[i];
        		++count;
        	} else if (value != nums[i]) {
        		--count;
        	} else {
        		++count;
        	}
        }
        return value;
    }
};