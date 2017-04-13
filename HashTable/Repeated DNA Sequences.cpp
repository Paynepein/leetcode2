class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
    	vector<string> res;
    	if (s.size() <= 10) return res; 
  		unordered_map<int64_t, int> mp;      
  		int maxi = s.size()-10;
  		int64_t sequence = s[0], exp = 1;
  		for (int i = 1; i < 10; ++i) {
  			sequence = sequence * 10 + s[i];
  			exp *= 10;
  		}
  		mp[sequence] = 1;
  		for (int i = 1; i <= maxi; ++i) {
  			sequence -= s[i-1] * exp;
  			sequence = sequence * 10 + s[i+9];
  			if (++mp[sequence] == 2) res.push_back(s.substr(i, 10));
  		}
  		return res;
    }
};