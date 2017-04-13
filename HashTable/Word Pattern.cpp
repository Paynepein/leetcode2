class Solution {
public:
    bool wordPattern(string pattern, string str) {
		vector<string> vec;
		splice(str, ' ', vec);
		if (pattern.size() != vec.size()) return false;
		unordered_map<char, int> mp1;
		unordered_map<string, int> mp2;
		for (int i = 0; i < pattern.size(); ++i) {
			if (mp1[pattern[i]] != mp2[vec[i]]) return false;
			mp1[pattern[i]] = mp2[vec[i]] = i+1;
		}
		return true;
    }

    void splice(string str, char c, vector<string>& vec) {
    	int start = 0, end = str.find_first_of(c);
    	while (end != string::npos) {
    		vec.push_back(str.substr(start, end-start));
    		start = end+1;
    		end = str.find_first_of(c, start);
    	}
    	if (start < str.size()) {
    		vec.push_back(str.substr(start));
    	}
    }
};