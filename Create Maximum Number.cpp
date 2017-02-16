class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int m = min(k, nums1.size());
        for (int i = max(0, k - nums2.size()); i <= m; ++i) {
        	for ()
        }
    }

    vector<int> maxNumberHelper(vector<int>& nums, int k) {
    	vector<int> res(k, 0);
    	res[0] = nums[0];
    	int index = 1;
    	for (int i = 1; i < nums.size(); ++i) {
    		while (index > 0 && k - index < nums.size() - i && res[index-1] < nums[i]) {
    			--index;
    		}
    		if (index + 1 < k) {
    			res[index++] = nums[i];
    		}
    	}
    	return res;
    }
};