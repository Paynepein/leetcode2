class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
        	int j = i;
        	while (nums[nums[j]-1] != nums[j]) {
        		swap(nums[nums[j]-1], nums[j]);
        	}
        }
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] != i+1) {
        		res.push_back(i+1);
        	}
        }
        return res;
    }
};