class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        int left = 0, i = 1;
        for (; i < nums.size(); ++i) {
        	if (nums[i] != nums[i-1] + 1) {
        		if (left == i-1) {
        			res.push_back(to_string(nums[left]));
        		} else {
        			res.push_back(to_string(nums[left]) + "->" + to_string(nums[i-1]));	
        		}
        		left = i;
        	}
        }
        if (left < i-1) {
        	res.push_back(to_string(nums[left]) + "->" + to_string(nums.back()));
       	} else {
       		res.push_back(to_string(nums.back()));
       	}
        return res;
    }
};