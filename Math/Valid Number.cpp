class Solution {
public:

	bool checkScientificNumber(string s) {
		size_t index = s.find_first_of("e");
		if (index == 0 || index == s.size()-1) return false;
		bool res = checkFloatingNumber(s.substr(0, index));
		if (s[index+1] == '+' || s[index+1] == '-') ++index;
		return  res && checkInteger(s.substr(index+1));
	}

	bool checkFloatingNumber(string s) {
		if (s == ".") return false;
		int index = s.find_first_of(".");
		bool res = index == 0 || checkInteger(s.substr(0, index));
		++index;
		while (index < s.size() && isdigit(s[index])) ++index;
		if (index == s.size()) return res;
		return false;
	}

	bool checkInteger(string s) {
		if (s.size() == 0) return false;
		int start = 0;
		while (start < s.size()) {
			if (!isdigit(s[start++])) return false;
		}
		return true;
	}

	string removeBlank(string s) {
		int start = 0;
		while (start < s.size() && isblank(s[start])) ++start;
		if (start < s.size() && (s[start] == '+' || s[start] == '-')) ++start;
		s = s.substr(start);
		int len = s.size();
		while (len > 0 && isblank(s[len-1])) --len;
		s = s.substr(0, len);
		return s;
	}

    bool isNumber(string s) {
    	s = removeBlank(s);
  		if (s.find_first_of("e") != string::npos) return checkScientificNumber(s);
  		if (s.find_first_of(".") != string::npos) return checkFloatingNumber(s);
  		return checkInteger(s);
    }
};