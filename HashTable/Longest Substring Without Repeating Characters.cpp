class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mp[128];
        memset(mp, -1, sizeof(mp));
        int res = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
        	if (mp[s[i]] >= start) {
        		res = max(res, i - start);
        		start = mp[s[i]]+1;
        	}
        	mp[s[i]] = i;
        }
        res = max(res, int(s.size() - start));
        return res;
    }
};