class Solution {
public:
    int myAtoi(string str) {
  		int ans = 0, start = 0, neg = 0;
  		while (start < str.size()) {
  			if (!isblank(str[start])) break;
  			++start;
  		}
  		if (start == str.size()) return 0;
  		if (str[start] == '-') {
  			neg = 1;
  			++start;
  		} else if (str[start] == '+') {
  			++start;
  		}
  		while (start < str.size()) {
  			if (!isdigit(str[start])) break;
  			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[start] - '0' > INT_MAX % 10)) return neg ? INT_MIN : INT_MAX;
  			ans = ans * 10 + str[start++] - '0';
  		}
  		return neg ? -1 * ans : ans;
    }
};