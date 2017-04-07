class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> res;
    	int l = words[0].size(), maxI = s.size() - l*words.size(), maxJ = s.size() - l, j;
        for (int i = 0; i <= maxI; ++i) {
        	unordered_map<string, int> mp;
        	for (string w : words) ++mp[w];
        	for (j = i; j <= maxJ; j += l) {
        		string sub = s.substr(j, l);
        		if (mp[sub] == 0) break;
        		--mp[sub];
        	}
        	if (j-i >= l*words.size()) res.push_back(i);
        }
        return res;
    }
};