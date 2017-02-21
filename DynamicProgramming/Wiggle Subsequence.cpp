class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
        vector<int> big(nums.size(), 1);
        vector<int> small(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
        	if (nums[i] < nums[i-1]) {
        		small[i] = max(big[i-1] + 1, small[i-1]);
        		big[i] = big[i-1];
        	} else if (nums[i] > nums[i-1]) {
       			big[i] = max(small[i-1] + 1, big[i-1]);
       			small[i] = small[i-1];
       		} else {
       			big[i] = big[i-1];
       			small[i] = small[i-1];
       		}
        }
        return max(big[nums.size()-1], small[nums.size()-1]);
    }
};