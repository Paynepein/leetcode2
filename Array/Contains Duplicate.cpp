class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for (int n : nums) {
        	if (st.count(n) == 1) return true;
        	st.insert(n);
        }
        return false;
    }
};