class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int n : nums1) ++mp[n];
        for (int n : nums2) {
        	if (mp[n] > 0) {
        		res.push_back(n);
        		--mp[n];
        	}
        }
        return res;
    }
};