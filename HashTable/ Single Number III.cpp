class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    	vector<int> res(2, 0);
        int xxor = 0;
        for (int n : nums) xxor ^= n;
        xxor = xxor ^ (xxor-1) & xxor;
    	for (int n : nums) {
    		if (n & xxor) {
    			res[0] ^= n;
    		} else {
    			res[1] ^= n;
    		}
    	}
    	return res;
    }
};