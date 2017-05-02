class Solution {
public:
    int findNthDigit(int n) {
  		int len = 1, start = 1;
  		long long num = 9;
  		while (n > len * num) {
  			n -= len * num;
  			num *= 10;
  			++len;
  			start *= 10;
  		}
  		start += (n-1) / len;
  		string s = to_string(start);
  		return s[(n-1)%len] - '0';
    }
};