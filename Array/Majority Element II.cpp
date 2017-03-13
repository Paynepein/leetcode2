class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> res;
    	if (nums.size() == 0) return res;
    	if (nums.size() == 1) {
    		res.push_back(nums[0]);
    		return res;
    	}
  		int count1 = 0, curr1 = nums[0], count2 = 0, curr2 = nums[0];
  		for (int i = 0; i < nums.size(); ++i) {
  			if (count1 > 0 && curr1 == nums[i]) {
  				++count1;
  			} else if (count2 > 0 && curr2 == nums[i]) {
  				++count2;
  			} else if (count1 == 0) {
  				curr1 = nums[i];
  				count1 = 1;
  			} else if (count2 == 0) {
  				curr2 = nums[i];
  				count2 = 1;
  			} else {
  				--count1;
  				--count2;
  			}
  		}
  		count1 = count2 = 0;
  		for (int i = 0; i < nums.size(); ++i) {
  			if (nums[i] == curr1) {
  				++count1;
  			} else if (nums[i] == curr2) {
  				++count2;
  			}
  		}
  		if (count1 > nums.size() / 3) {
  			res.push_back(curr1);
  		}
  		if (count2 > nums.size() / 3) {
  			res.push_back(curr2);
  		}
  		return res;
    }
};