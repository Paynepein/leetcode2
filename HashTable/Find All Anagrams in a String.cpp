class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> res;
    	int count = 0;
        unordered_map<char, int> mp;
        for (char c : p) ++mp[c];
        for (int left = 0, right = 0; right < s.size(); ) {
        	if (mp[s[right++]]-- > 0) {
        		++count;
        	}
        	if (count == p.size()) res.push_back(left);
        	if (right - left == p.size()) {
        		if (mp[s[left++]]++ >= 0) {
        			--count;
        		}
        	}
        }

        return res;
    }
};