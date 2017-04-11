class Solution {
public:
    string minWindow(string s, string t) {
    	if (s == "" || t == "") return "";
  		unordered_map<char, int> mp, dic;
  		for (char c : t) ++mp[c];
  		int minI = -1, minLen = s.size()+1, left = -1;
  		int sl = s.size(), tl = t.size(), count = 0, curlen = 0;
  		for (int i = 0; i < sl; ++i) {
  			if (left >= 0) ++curlen;
  			if (mp.find(s[i]) != mp.end()) {
  				++dic[s[i]];
  				if (dic[s[i]] <= mp[s[i]]) ++count;
  				if (left == -1) {
  					left = i;
  					curlen = 1;
  				}

  				if (count == tl) {
  					while (mp.find(s[left]) == mp.end() || dic[s[left]] > mp[s[left]]) {
  					    if (mp.find(s[left]) != mp.end()) {
  					        --dic[s[left]];   
  					    }
  						++left;
  						--curlen;
  					}
  					if (curlen < minLen) {
  						minI = left;
  						minLen = curlen;
  					}
  					--dic[s[left]];
  					++left;
  					--curlen;
  					--count;
  					while (left <= i && (mp.find(s[left]) == mp.end() || dic[s[left]] > mp[s[left]])) {
  						if (mp.find(s[left]) != mp.end()) --dic[s[left]];
  						++left;
  						--curlen;
  					}		
  				}
  			}
  		}
  		if (minI == -1) return "";
  		return s.substr(minI, minLen);
    }

};